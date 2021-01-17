#include "db.h"

void create_db(const char* csv, const char *db)
{
	int iStringLength = 0;
	char sFileString[ BUFFER ];
	
	checkInputFile(csv);
	checkOutputFile(db);

	fgets( sFileString, BUFFER, fpData );
	rewind( fpOutput );

	printf("%10s%20s%20s%20s\n", "Name", "Mode;", "Year", "q","w","e","r");
	printf("--------------------------------------------------------------------------\n");
	while ( !feof( fpData ) )
	{
		iStringLength = strlen(sFileString);
		iStringLength--;
	
		if( sFileString[iStringLength] == '\n' )
		{
			sFileString[iStringLength] = '\0';
		}

		writeOutputFile( sFileString );

		fgets( sFileString, BUFFER, fpData ); 
	}

	fclose(fpData);
	fclose(fpOutput);

	return 0;
}


void checkInputFile( char *sFileName )
{
	if( ( fpData = fopen(sFileName, "r" ) ) == NULL )
	{
		printf("%s could not be opened.\n", sFileName);
		exit(1);
	}
}

void checkOutputFile( char *sFileName )
{
	char cAnswer;

	if( ( fpOutput = fopen(sFileName, "rb") ) != NULL )
	{
		printf("%s file exists.  Overwrite? y or n ", sFileName );
		scanf( "%c", &cAnswer );
		fflush;
		fclose( fpOutput );

		if( cAnswer == 'y' )
		{
			if( ( fpOutput = fopen(sFileName, "wb") ) == NULL )
			{
				printf("%s could not be opened.\n", sFileName );
				exit(1);
			}
		}
		else
		{
			printf( "Cannot overwrite %s file, exiting program.\n", sFileName );
			exit(1);
		}
	}
	else
	{
		if( ( fpOutput = fopen(sFileName, "wb") ) == NULL )
		{
			printf("%s could not be opened.\n", sFileName );
			exit(1);
		}
	}
}

void writeOutputFile( char *sFileData )
{
	SCAN_INFO temp = {"","",0.0,0.0};
	char *pToken = NULL;

	pToken = strtok(sFileData, "," );

	strcpy( temp.name, pToken );
	printf( "%4s", temp.name );
	pToken = strtok(NULL, "," );

	strcpy( temp.model, pToken );
	printf("%32s", temp.model);
	pToken = strtok(NULL, "," );

	temp.year = atoi( pToken );
	printf("%d", temp.year);
	pToken = strtok(NULL, "," );

	temp.q = atof( pToken );
	printf("%20.2f\n", temp.q);
  pToken = strtok(NULL, "," );

  temp.w = atoi( pToken );
	printf("%d", temp.w);
  pToken = strtok(NULL, "," );

  temp.e = atoi( pToken );
	printf("%d", temp.e);
  pToken = strtok(NULL, "," );

  temp.r = atoi( pToken );
	printf("%d", temp.r);

	fwrite( &temp, sizeof( SCAN_INFO ), 1, fpOutput );
}

int make_index(const char *db, const char *field_name) {
  int	iDataRecordCount;
	long lFilePos;

	indexKey = ACCOUNT_NAME;

	checkInputFile1(db);
	checkOutputFile1();

	iDataRecordCount = checkRecordCount();

	lFilePos = ftell(fpData);

	writeIndexHeader( iDataRecordCount );
	writeIndexFile( iDataRecordCount, lFilePos ) ;

	fclose( fpData );
	fclose( fpIndexFile );

	return 0;
}

int checkRecordCount( void )
{
	int iRecordCount = 0;
	iRecordCount = fileSize( fpData ) / sizeof(SCAN_INFO);
	rewind(fpData);

	return iRecordCount;
}

void checkInputFile1( char *sFileName )
{
	if( ( fpData = fopen(sFileName, "rb" ) ) == NULL )
	{
		printf("%s could not be opened.\n", sFileName);
		exit( EXIT_FAILURE );
	}
}

void checkOutputFile1( void )
{
	if( ( fpIndexFile = fopen("all.idx", "wb" ) ) == NULL )
	{
		printf("all.idx could not be opened.\n");
		exit( EXIT_FAILURE );
	}
}

void writeIndexHeader( int iDataRecordCount )
{
	IndexHeader	indexHeader;

	indexHeader.idxKey = indexKey;
	strcpy(indexHeader.appName, APP_NAME);
	indexHeader.recCount = iDataRecordCount;

	fwrite(&indexHeader, sizeof( IndexHeader ), 1, fpIndexFile);
}

void writeIndexFile( int iDataRecordCount, long filePos )
{
	int iCount;
	int iReadCount;
	int	iWriteCount;
	int iIndexRecordCount = 0;

	SCAN_INFO temp = {"","", 0, 0.0,0,0,0};
	IndexRecord	*indexRecords;
	indexRecords = (IndexRecord *) calloc(iDataRecordCount, sizeof(IndexRecord));
	iReadCount = fread( &temp, sizeof( SCAN_INFO ), 1, fpData );
	while (!feof(fpData) && (iReadCount == 1))
	{
		strcpy( indexRecords[iIndexRecordCount].key.name, temp.name );
		indexRecords[iIndexRecordCount].filePos = filePos;
		iIndexRecordCount++;              
		filePos = ftell(fpData);
		iReadCount = fread(&temp, sizeof( SCAN_INFO ), 1, fpData);
	}
	qsort(indexRecords, iIndexRecordCount, sizeof( IndexRecord ), compare);

	printf("Index Header Size: %d\nIndex Record Size: %d\n\n"
		                    , sizeof( IndexHeader ), sizeof( IndexRecord ) );

	printf("Creating Index File\n\n");	
	printf("Index sorted by Account Name:\n\n");
	for( iCount = 0; iCount < iIndexRecordCount; iCount++ )
	{
		printf("%s\n", indexRecords[iCount].key.name);
	}

	iWriteCount = fwrite(indexRecords, sizeof( IndexRecord ), iIndexRecordCount, fpIndexFile);

	printf("\n%d Records Processed\n", iWriteCount);
	free( indexRecords );
}

long fileSize(FILE *input)
{
	long orgPos;
	long startPos;
	long endPos;

	orgPos = ftell(input); 
	rewind(input);
	startPos = ftell(input);
	fseek(input, 0, SEEK_END);
	endPos = ftell(input);
	fseek(input, orgPos, SEEK_SET); 
	
	return(endPos - startPos);
}


int compare(const void *left, const void *right)
{
	IndexRecord *pLeft = (IndexRecord *) left;
	IndexRecord *pRight = (IndexRecord *) right;
	return strcmp((pLeft->key.name), (pRight->key.name));
}



void checkHeader ( void )
{
	int iRecordCount;

	IndexHeader indexHeader;
	fread(&indexHeader, sizeof( IndexHeader ), 1, fpIndexFile);
	iRecordCount = fileSize(fpData) / sizeof( SCAN_INFO );
	if (strcmp(indexHeader.appName, APP_NAME) != 0)
	{
		printf("Data File Format is Invalid\n");
		fclose(fpData);
		fclose(fpIndexFile);
		exit( EXIT_FAILURE );
	}
	if (indexHeader.recCount != iRecordCount)
	{
		printf("Record Count Mismatch\n");
		fclose(fpData);
		fclose(fpIndexFile);
		exit( EXIT_FAILURE );
	}
}

void displaySortedData( void )
{
	int iReadCount;
  FILE *fp;
	IndexRecord indexTemp;
	SCAN_INFO temp = { "", "", 0, 0.0,0,0,0 };
  fp=fopen("all.txt", "a");

	fprintf(fp,"%10s%22s%18s%20s%d%d%d\n", "Name", "Model", "Year", "q","w","e","r");
	fprintf(fp,"--------------------------------------------------------------------------\n");

	iReadCount = fread(&indexTemp, sizeof(IndexRecord), 1, fpIndexFile);
			
	while ((!feof(fpIndexFile)) && (iReadCount == 1))
	{
		if (fseek(fpData, indexTemp.filePos, SEEK_SET) != 0)
		{
			printf("Seek Error\n");
			fclose(fpData);
			fclose(fpIndexFile);
			exit( EXIT_FAILURE );
		}
		fread(&temp, sizeof( SCAN_INFO ), 1, fpData);
		fprintf(fp,"%4s%32s%18.2f%20.2f%d%d%d\n", temp.name, temp.model, temp.year, temp.q,temp.w,temp.e,temp.r);
		iReadCount = fread(&indexTemp, sizeof(IndexRecord), 1, fpIndexFile);		
	}
}



void reindex(const char *db) {
  int iReadCount;
	IndexRecord indexTemp;
  iReadCount = fread(&db, sizeof(IndexRecord), 1, fpIndexFile);
			
	while ((!feof(fpIndexFile)) && (iReadCount == 1)) {
  }
}

void print_db(const char *db) {
  	checkInputFile( db );
    checkIndexFile( "all.txt" );
    checkHeader();
    displaySortedData();

    fclose( fpData );
    fclose( fpIndexFile );
}

void del_scanner(const char *db, int id) {
  IndexRecord indexTemp;
  int iReadCount;

	iReadCount = fread(&indexTemp, sizeof(IndexRecord), 1, fpIndexFile);
			
	while ((!feof(fpIndexFile)) && (iReadCount == 1)) {
    if (&indexTemp.key == id) {
      continue;
    }
  }
  reindex(db);
  return NULL;
}

void add_scanner(const char *db, const char* scanner_str) {
  IndexRecord indexTemp;
  int iReadCount;
  int iCount;
	int iReadCount;
	int	iWriteCount;
	int iIndexRecordCount = 0;

	SCAN_INFO temp = {"","", 0, 0.0,0,0,0};
	IndexRecord	*indexRecords;
	indexRecords = (IndexRecord *) calloc(100, sizeof(IndexRecord));
	iReadCount = fread( &temp, sizeof( SCAN_INFO ), 1, fpData );

	iReadCount = fread(&indexTemp, sizeof(IndexRecord), 1, fpIndexFile);
			
	while ((!feof(fpIndexFile)) && (iReadCount == 1)) {
    }
  fread(&temp, sizeof( SCAN_INFO ), 1, fpData);
	iWriteCount = fwrite(indexRecords, sizeof( IndexRecord ), iIndexRecordCount, fpIndexFile);
  reindex(db);
}

SCAN_INFO* select(const char *db, const char *field, const char *value) {
	IndexRecord indexTemp;
  int iReadCount;
	SCAN_INFO temp = { "", "", 0, 0.0,0,0,0 };

	iReadCount = fread(&indexTemp, sizeof(IndexRecord), 1, fpIndexFile);
			
	while ((!feof(fpIndexFile)) && (iReadCount == 1)) {
    if (temp.name == value) {
      return &temp;
    }
  }
  return NULL;
}

void print_rec_set(SCAN_INFO *rs) {
  printf("%10s%22s%18s%20s%d%d%d\n", "Name", "Model", "Year", "q","w","e","r");
	printf("--------------------------------------------------------------------------\n");
  printf("%10s%22s%18s%20s%d%d%d",rs->name,rs->model,rs->year,rs->q,rs->w,rs->e,rs->r);
}