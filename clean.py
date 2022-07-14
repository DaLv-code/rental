import random
stud_list = ["김류은", "김종욱", "김준형", "김진우", "노도현", "류가미", "박성진","박승렬",  "방은혁", "성민식",  "양현동", "이유진", "이의현", "임근영", "정정빈", "최명석", "최양원", "황인선"]
clean_list =[]
day_list = ["7월 13일: ", "7월 20일: ", "8월 10일: ", "8월 17일: "]

random.shuffle(stud_list)

print(str(day_list[0])+str(stud_list[0:4]))

print(str(day_list[1])+str(stud_list[4:8]))

print(str(day_list[2])+str(stud_list[8:12]))

print(str(day_list[3])+str(stud_list[12:16]))
    
print("제외: "+str(stud_list[16:19]))
