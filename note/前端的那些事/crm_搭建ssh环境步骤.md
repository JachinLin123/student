## 第一步 导入jar包

## 第二步 搭建struts2环境
    * 创建action，创建struts。xml配置文件，配置action
    * 配置struts2的过滤器

## 第三步 搭建hibernate环境
    * 创建实体类
    * 配置实体类和数据库表的映射关系
    * 创建hibernate核心配置文件
    * 引入映射配置文件

## 第四步 搭建spring环境
    * 创建spring核心配置文件
    * 让spring配置文件在服务器启动时候加载
    * 配置监听器
    * 指定spring配置文件位置

## 第五步 struts2和spring整合
    * 把action在spring配置(action多实例的)
    * 在struts.xml中action标签class属性里面写bean的id值

## 第六步 spring和hibernate整合
    * 把hibernate核心配置文件中数据库配置，在spring里面配置
    * 把hibernate的sessionFactory在spring配置
    
## 第七步 在dao里面使用hibernateTemplate
    * 在dao注入hibernateTemplate对象
    * 在hibernateTemplate对象中注入sessionFactory
