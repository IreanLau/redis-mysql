#ifndef __SQL_CONNECT__
#define __SQL_CONNECT__

#include<mysql.h>
#include<string>
#include<stdlib.h>

#include<iostream>
using namespace std;


//char* lib_path="LD_LIBRARY_PATH=/usr/lib/mysql";

class sql_connecter{
	public:
		sql_connecter(const string& _host,\
				const string& _usr,\
				const string& _passwd,\
				const string& _db);
		~sql_connecter();
		void show_info();
		bool begin_connect();
		bool close_connect();
		bool insert_sql(const std::string &data);
		bool select_sql(string[],string _out_str[][3],int& _out_row);
//		bool updata_sql();
//		bool delete_sql();
//		bool delete_table();
		bool create_table();
		void connSqlAndShow();
			
	private:
		MYSQL_RES* res;
		MYSQL* mysql_base;
		string host;
		string user;
		string passwd;
		string db;
};

#endif
