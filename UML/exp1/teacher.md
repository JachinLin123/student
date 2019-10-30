@startuml
left to right direction
actor 教师
教师 --> (登录)
(找回密码) .> (登录) : <<extend>>
教师 --> (录入学生成绩)
教师 --> (修改学生成绩)
教师 --> (查询学生成绩)
教师 --> (删除学生成绩)
@enduml