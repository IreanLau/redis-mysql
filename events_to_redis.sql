-- events_to_redis.sql
 
 SELECT CONCAT(
  "*4\r\n",
  '$', LENGTH(redis_cmd), '\r\n',
  redis_cmd, '\r\n',
  '$', LENGTH(redis_key), '\r\n',
  redis_key, '\r\n',
  '$', LENGTH(hkey), '\r\n',
  hkey, '\r\n',
  '$', LENGTH(hval), '\r\n',
  hval, '\r'
)
FROM (
  SELECT
    'HSET' as redis_cmd,
	  'events_all_time' AS redis_key,
	  action AS hkey,
	  count AS hval
	  FROM events_all_time
	) AS t
