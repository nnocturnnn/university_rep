

typedef struct{
  int rec_nmb;
  SCAN_INFO *recs;
}RECORD_SET;



void create_db(const char* csv, const char *db) {

 }


int make_index(const char *db, const char *field_name) {

}


RECORD_SET * get_recs_by_index(const char *dba , char *indx_field ) {

}

void reindex(const char *db) {

}


void del_scanner(const char *db, int id) {

}

void add_scanner(const char *db, const char* scanner_str) {

}

RECORD_SET* select(const char *db, const char *field, const char *value)