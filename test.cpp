
#include<stdio.h>
#include<hiredis/hiredis.h>
#include<sql_connect.h>



int main(int argc,char* argv[])
{
	redisContext* conn = redisConnect("127.0.0.1",6379);
	if(conn!=NULL && conn->err)
	{
		printf("connection error:%s\n",conn->errstr);
	}
	else
	{
		//printf("connect success\n");
	}
/**********************************************************/	
	const std::string _host = "127.0.0.1";
	const std::string _user = "root";
	//const std::string _host = "192.168.253.129";
	//const std::string _user = "httpd";
	const std::string _passwd = "1205";
	const std::string _db   = "redis";
	//const std::string data  = "'ZZZZZZZZZZZZZZZZZZZZZZZ', 14";
	sql_connecter sqlconn(_host, _user, _passwd, _db);
	sqlconn.begin_connect();

	printf("will connsql,if ok,sqlShow\n");
	sqlconn.connSqlAndShow();

	redisReply* reply = (redisReply*)redisCommand(conn,"auth ireanlau");
	reply = (redisReply*)redisCommand(conn,"hgetall events_all_time");
	int i=0;
	string Ins;						//用于插入数据库
	 for (; i < reply->elements; ++i) {
		     redisReply* childReply = reply->element[i];
			     //之前已经介绍过，get命令返回的数据类型是string。
	 			     //对于不存在key的返回值，其类型为REDIS_REPLY_NIL。
			if (childReply->type == REDIS_REPLY_STRING)
			{
				 printf("The value is %s.\n",childReply->str);
				 string tmp="'";
				 tmp+=childReply->str;
				 tmp+="'";
	 			 Ins+=tmp;
			}
			if(i%2==0)
			{
				Ins+=",";
			}
			else
			{
	 			sqlconn.insert_sql(Ins);
				Ins.clear();
			}
	     }
	freeReplyObject(reply);
	redisFree(conn);

	printf("after transferred, sqlShow again\n");
	sqlconn.connSqlAndShow();

	return 0;
}

