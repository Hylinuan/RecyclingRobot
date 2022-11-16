import os
import glob

# classes = ['plastic','papper','glass','iron','aluminum']
Image = []

# save_file = open('F:/SHU/recycle/batch/imagelist', 'w')
class_path='/home/rec_robot/recycle/keras/testing/'
print(class_path)
for img_name in os.listdir(class_path):
    Image.append(class_path+img_name+' '+img_name[0:1])
    print(class_path+img_name+' '+img_name[0:1])
with open('/home/rec_robot/recycle/batch/imagelist_test.lst', 'w') as f:
    for item in Image:
        f.write("%s\n" % item)
f.close()

