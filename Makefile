BIN=test
CC=g++
INCLUDE=-I/usr/include/hiredis -L/usr/lib -lhiredis -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient -I /home/lau/redis_connect_mysql/transferredByCpp/redisc

SRC=test.cpp sql_connect.cpp


$(BIN):$(SRC)
	$(CC) -o $@ $^ $(INCLUDE)  -ldl -lrt -g -D_DEBUG_
.PHONY:clean
clean:
	rm -rf $(BIN)
