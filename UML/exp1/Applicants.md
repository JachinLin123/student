@startuml
left to right direction
actor 应聘者
应聘者 --> (登录)
(登录) .> (注册) :  <<include>>
应聘者 --> (查询个人信息和应聘信息)
应聘者 --> (维护个人信息和应聘信息)
应聘者 --> (选择职位进行应聘)
@enduml