## 盛赞redis

* 高性能Key-Value服务器
* 多种数据结构
* 丰富的功能
* 高可用分布式支持

### Redis初认识

* redis是什么
    * 开源(作者：Salvatore Sanfilippo(antirez))
    * 多种数据结构
    * 基于键值的存储服务系统
    * 高性能
* redis特性回顾
    * 速度快
    ```
    官方速度：10w OPS
    存储：内存
    语言：C语言
    线程模型：单线程
    ```
    * 持久化
        ```
        将所有数据保持在内存中，将数据的更新将异步保存在磁盘上
        ```
    * 多种数据结构
        ```
        Strings/Blobs/Bitmaps
        Hash Tables(objects)
        Linked Lists
        Sets
        Sorted Sets

        新版本：
            BitMaps：位图
            HyperLogLog：嘲笑内存唯一计数
            GEO：地理信息定位

        ```
    * 支持多种编程语言
        ```
        java,php,python,ruby,lua,nodejs
        ```
    * 功能丰富
        ```
        发布订阅;事物;Lua脚本;pipeline
        ```
    * 简单
        ```
        23.000 lines of code
        不依赖外部库(like libevent)
        单线程模型
        ```
    * 主从复制
        ```
                ---从
        主--copy---从
                ---从
        ```
    * 高可用、分布式
        ```
        高可用--》redis-Sentinel(v2.8)支持高可用
        ```

#### redis典型的应用场景
* 缓存系统
    ```
    App Server
        |
      cache
        |
      Storage
    ```

* 计数器
    ```
    评论，转发
    ```
* 消息队列
    ```
    products--message--customer
    ```
* 排行榜
* 社交网络
* 实时系统

#### redis安装
* redis安装
    ```
    wget http://download.redis.io/releases/redis-3.0.7.tar.gz
    tar -xzf redis-3.0.7.tar.gz
    In -s redis-3.0.7 redis
    cd redis
    make&&make install

    ```
   
* 可执行文件说明
    ```
     redis-server      ==>redis服务器
     redis-cli         ==>redis命令行客户端
     redis-benchmark   ==>redis性能测试
     redis-check-aof   ==>aof文件修复
     redis-check-dump  ==>rdb文件修复
     redis-sentinel    ==>sentinel服务器
    ```
* 三种启动方法
    * 最简启动
        ```
        启动：
        redis-server
        验证：
        ps -ef|grep redis
        netstat -antpl|grep redis
        redis-cli -h ip -p port ping
        ```
    * 动态参数启动
        ```
        redis-server -port 6380
        ```
    * 配置文件启动
        ```
        redis-server configPath
        ```
    * 比较
        ```
        生产环境选择配置启动
        单机多实例配置文件可以用端口区分开

        ```
* 简单的客户端连接
    ```
    redis-cli -h 114.55.32.150 -p 6384
    ping
    set hello world
    get hello
    (类似于打乒乓球)
    状态回复：ping--->pong
    错误回复：hget hello field-->(error) WRONGGTYPE Operation against
    整数回复：incr hello-->(integer) 1
    字符串回复：get hello -->"world"
    多行字符串回复：mget hello foo
    1)"world"
    2)"bar"
    ```
* redis常用配置
    ```
    daemonize:是否为守护进程
    port:redis对外端口号
    logfile:redis系统日志
    dir:redis工作目录()
    默认端口：6379(merz意大利歌手名字，诺基亚)
    配置文件步骤：
    mkdir config
    cp redis.conf config
    cd config
    vim redis-6381.confg
    cat redis-6381.conf| grep -v "#" | grep -v "^$" > redis-6382.conf
    redis-server config/redis-6382.conf

    ```

### API的理解和使用

* 通用命令
    * 通用命令
        ```python
        keys [patter] #遍历所有key;一般不在生产环境中使用
            热备从节点
            scan
        dbsize #计算key的总数(内置计数器)
        exists key  #检查key是否存在(存在返回1，不存在返回0)
        del key #删除指定的key
        expire key seconds  #key在sencods过期
            ttl key #查看key剩余过期时间
            persist key # 去掉key的过期时间
        type key    #返回key的类型
        除了keys:O(n),其他都是O(1)
        ```
    * 数据结构和内部编码
    * 单线程架构
* 字符串类型
* 哈希类型
* 列表类型
* 集合类型
* 有序集合


### Redis客户端使用

### 瑞士军刀Redis

### Redis持久化的取舍和选择

### Redis复制的原理和优化

### Redis Sentinel

### Redis Cluster
