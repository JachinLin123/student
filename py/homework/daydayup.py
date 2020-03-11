'''
一年365天，如果努力每天提高1%，休息时每天下降1%(周一-周五工作，周末双休),进步还是退步？？？
'''
import math
#假设一年第一天以周一开始


week = int(365 / 7)
m = 365 % 7
result = pow(1.01, week * 5 + m) - pow(0.01, week * 2)
if(result > 0):
    print("恭喜你进步了!成绩为：")
    print(result)
else:
    print("sorry, 今年你退步了哦！！！")

