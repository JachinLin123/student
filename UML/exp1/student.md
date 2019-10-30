@startuml
left to right direction
actor 学生
学生 --> (登录)
(找回密码) .> (登录) : <<extend>>
学生 --> (查询个人信息)
@enduml