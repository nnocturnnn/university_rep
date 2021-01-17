#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

void checkCommandArguments( int iNumber );
void checkInputFile( char *sFileName );
void checkOutputFile( char *sFileName );
void writeOutputFile( char *sFileData );
void checkCommandArguments( int iNumber );
void checkInputFile1( char *sFileName );
int checkRecordCount( void );
void checkOutputFile1( void );
void writeIndexHeader( int iDataRecordCount );
void writeIndexFile( int iDataRecordCount, long filePos );
long fileSize(FILE *input);
int compare(const void *left, const void *right);

FILE *fpData;
FILE *fpOutput;
FILE *fpIndexFile;

#define MAXCHAR 30
#define BUFFER 100
#define BUFFER_SIZE 1024
#define APP_NAME "Assignment8"
#define EXIT_FAILURE 1
typedef enum {ACCOUNT_NUMBER, ACCOUNT_NAME, BALANCE} IndexKey;

typedef struct{
  int rec_nmb;
  SCAN_INFO *recs;
}RECORD_SET;

typedef union
{
	char name[ MAXCHAR ];
	char model[ MAXCHAR ];
    int year;
	double q;
} KeyType;

typedef struct
{
	KeyType		key;
	long		filePos;
} IndexRecord;

typedef struct
{
	IndexKey	idxKey;	
	char		appName[ MAXCHAR ];
	int			recCount;
} IndexHeader;

IndexKey indexKey;


typedef struct{
  char name[30];
  char model[30];
  int year;
  double q;
  int w;
  int e;
  int r;
}SCAN_INFO;