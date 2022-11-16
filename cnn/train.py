# -*- coding: utf-8 -*-
"""
Created on Mon May  7 20:21:55 2018

@author: Joey
"""

# -*- coding: utf-8 -*-
"""
Created on Mon May  7 19:44:44 2018

@author: Joey
"""
from tensorflow.keras.models import Sequential
from keras.layers.core import Dense, Dropout, Activation
from keras.optimizers import SGD
from keras import backend as K

import tensorflow as tf
from tensorflow.python.tools import freeze_graph, optimize_for_inference_lib

#from keras.datasets import mnist  
from keras.utils import np_utils  
import numpy as np  
import cv2
import glob
import random
from sklearn.model_selection import train_test_split 
from keras.layers import Flatten,Conv2D,MaxPooling2D  
import pandas as pd  
import os

import matplotlib.image as mpimg
import matplotlib.pyplot as plt

def is_int(value):
    try:
        int(value)
        return True
    except:
        return False
def is_float(value):
    try:
        float(value)
        return True
    except:
        return False
#---------------------手動設定值---------------------------------------------------#
os.chdir(r'/home/rec_robot/recycle')
classes = {'plastic','papper','glass','iron','aluminum'} #設定5個類別(5個資料夾)
#classes = {'aluminum'} #設定5個類別(5個資料夾)
testPath = './test'
trainTimes = 100
dontwriteInputName = 10
pathCropNumber = 10  # tranPicture path to crop OK"01"  start index
testCropNumber = 10  # testPicture path to crop OK"01"  start index

#---------------------------------------------------------------------------------------#
##
def save_model(model, network_path):
    if not os.path.exists(network_path):
       os.makedirs(network_path)
    open(os.path.join(network_path, 'architecture.json'), 'w').write(model.to_json())
    model.save_weights(os.path.join(network_path, 'weights.h5'), overwrite=True)
    

def export_model_for_mobile(model_name, input_node_name, output_node_name):
    tf.train.write_graph(K.get_session().graph_def, 'out', \
        model_name + '_graph.pbtxt')

    tf.train.Saver().save(K.get_session(), 'out/' + model_name + '.chkp')

    freeze_graph.freeze_graph('out/' + model_name + '_graph.pbtxt', None, \
        False, 'out/' + model_name + '.chkp', output_node_name, \
        "save/restore_all", "save/Const:0", \
        'out/frozen_' + model_name + '.pb', True, "")

    input_graph_def = tf.GraphDef()
    with tf.gfile.Open('out/frozen_' + model_name + '.pb', "rb") as f:
        input_graph_def.ParseFromString(f.read())

    output_graph_def = optimize_for_inference_lib.optimize_for_inference(
            input_graph_def, [input_node_name], [output_node_name],
            tf.float32.as_datatype_enum)

    with tf.gfile.FastGFile('out/tensorflow_lite_' + model_name + '.pb', "wb") as f:
        f.write(output_graph_def.SerializeToString())

def load_split_fingerprint():
    print("Processing load_split_fingerprint", flush=True)

# ------------------train-----------------------#
    #img = cv2.imread('./iron/iron1.png', 1)
    #cv2.imshow('Image',img)
    #input()

    for index,name in enumerate(classes):
        class_path='./'+name+'/'
        for img_name in os.listdir(class_path):
            FList =glob.glob(class_path + img_name)
            img = cv2.imread(class_path + img_name)
            plt.imshow(img)
            plt.show()

    FListLen=len(FList)
    print(FListLen)
    y = np.full((FListLen), 0, dtype=int)
    random.shuffle(FList)
    
#    for yy in range(len(y)):
#        y[yy] = int(FList[yy][pathCropNumber:pathCropNumber+2])-1    #OK "09" picture is 9  OK"10" picture is 10
#        if dontwriteInputName==0:
#            print(FList[yy])
#            print(y[yy])
            
# -------------------test---------------------#
            
    for img_name in testPath: 
        TList =glob.glob(testPath + '/' +img_name)

    TListLen=len(FList)
    print(FListLen)
    y2 = np.full((TListLen), 0, dtype=int)
    random.shuffle(TList)
#    for yy2 in range(len(y2)):
#        y[yy2] = int(TList[yy2][pathCropNumber:pathCropNumber+2])-1    #OK "09" picture is 9  OK"10" picture is 10
#        if dontwriteInputName==0:
#            print(TList[yy2])
#            print(y[yy2])


    X_trainFname,y_train = FList, y 
    X_testFname,y_test = TList, y2
    X_train = np.full((len(X_trainFname),2500), 0, dtype=np.float64)
    i=-1
    print("This is train picture path")

    for fname in X_trainFname:
        if dontwriteInputName==0:
            print(fname)
            img, i = cv2.imread(fname,0), i+1

#    X_train[i]=img.reshape(2500)
    X_test = np.full((len(X_testFname),2500), 0, dtype=np.float64)
    i=-1
    print("This is test picture path")
    for fname in X_testFname:
        if dontwriteInputName==0:
            print(fname)
    img, i = cv2.imread(fname,0), i+1
#    X_test[i]=img.reshape(2500)
    return X_train, X_test,X_trainFname,X_testFname,y_train,y_test

 
  
def isDisplayAvl():  
    return 'DISPLAY' in os.environ.keys()  
  
import matplotlib.pyplot as plt  
def plot_image(image):  
    fig = plt.gcf()  
    fig.set_size_inches(2,2)  
    plt.imshow(image, cmap='binary')  
    plt.show()  
  
def plot_images_labels_predict(images, labels, prediction, idx, num=10):  #10
    fig = plt.gcf()  
    fig.set_size_inches(12, 14)  
    if num > 25: num = 25               #25
    for i in range(0, num):  
        ax=plt.subplot(5,5, 1+i)        #5
        ax.imshow(images[idx], cmap='binary')  
        title = "l=" + str(labels[idx])  
        if len(prediction) > 0:  
            title = "l={},p={}".format(str(labels[idx]), str(prediction[idx]))  
        else:  
            title = "l={}".format(str(labels[idx]))  
        ax.set_title(title, fontsize=10)       #10
        ax.set_xticks([]); ax.set_yticks([])  
        idx+=1  
    plt.show()  
  
def show_train_history(train_history, train, validation):  
    plt.plot(train_history.history[train])  
    plt.plot(train_history.history[validation])  
    plt.title('Train History')  
    plt.ylabel(train)  
    plt.xlabel('Epoch')  
    plt.legend(['train', 'validation'], loc='upper left')  
    plt.show()  
    
#from utils import converters,formatters
    
#!/usr/bin/env python3  

def main():

    #img = cv2.imread('./iron/iron1.png', 1)
    #plt.imshow(img)
    #plt.show()
    #cv2.imshow('Image', img)
    #input()

    np.random.seed(20)    #10
         
# Read MNIST data  

    X_Train,X_Test ,X_trainFname,X_testFname, y_Train, y_Test = load_split_fingerprint()

  
# Translation of data  
    X_Train40 = X_Train.reshape(X_Train.shape[0], 50, 50, 1).astype('float32')  
    X_Test40 = X_Test.reshape(X_Test.shape[0], 50, 50, 1).astype('float32')  
# Standardize feature data  
    X_Train40_norm = X_Train40 / 255  
    X_Test40_norm = X_Test40 /255  

# Label Onehot-encoding  
    y_TrainOneHot = np_utils.to_categorical(y_Train)  
    y_TestOneHot = np_utils.to_categorical(y_Test)  

    
  
  
    model = Sequential()  
    
# Create CN layer 1  
    model.add(Conv2D(filters=16,  
                 kernel_size=(5,5),  
                 padding='same',  
                 input_shape=(50,50,3),
                 data_format='channels_last',  
                 activation='relu'))  
# Create Max-Pool 1  
    model.add(MaxPooling2D(pool_size=(2,2)))     # 3,3
  
# Create CN layer 2  
    model.add(Conv2D(filters=36,  
                 kernel_size=(3,3),           #5,5
                 padding='same',  
                 input_shape=(50,50,3),
                 data_format='channels_last',  
                 activation='relu'))  
  
# Create Max-Pool 2  
   # model.add(MaxPooling2D(pool_size=(2,2)))  #true
  
# Add Dropout layer  
    model.add(Dropout(0.05))   #0.25 

    model.add(Flatten())  
    model.add(Dense(128, activation='relu'))  
    model.add(Dropout(0.05))                   #0.5 
    model.add(Dense(20, activation='softmax'))  
    model.summary()  
    
    print("")  
    print("Step0")


# 定義訓練方式  
    model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])  

    print("Step0-1")
  
# 開始訓練  
    train_history = model.fit(x=X_Train40_norm,  
                          y=y_TrainOneHot, validation_split=0.2,  
                          epochs=trainTimes, batch_size=300, verbose=2)  
 
# 匯出成.pb檔
    # Save model
    save_model(model, "model")

    # Export model for tensorflow lite
    export_model_for_mobile("convnet", "conv2d_1_input", "dense_2/Softmax")
    model.summary()
#----------------------------------------
    
    print("Step1")
   # if isDisplayAvl():  
    #    show_train_history(train_history, 'acc', 'val_acc')  
     #   show_train_history(train_history, 'loss', 'val_loss')  
#-------------顯示成功率變化-----------------------------------------------------------------
    show_train_history(train_history, 'acc', 'val_acc')
     
     #----------------------------------------------------------------------------


    print("Step2")
    scores = model.evaluate(X_Test40_norm, y_TestOneHot)  
    print()  
    print("/t[Info] Accuracy of testing data = {:2.1f}%".format(scores[1]*100.0))  
    print("/t[Info] Making prediction of X_Test4D_norm")  
    prediction = model.predict_classes(X_Test40_norm)  # Making prediction and save result to prediction  
    print()  
    print("/t[Info] Show 10 prediction result (From 240):")  
    print("%s/n" % (prediction[240:250]))  

    if isDisplayAvl():  
        plot_images_labels_predict(X_Test, y_Test, prediction, idx=240)  


    print("/t[Info] Display Confusion Matrix:")  
    print("%s/n" % pd.crosstab(y_Test, prediction, rownames=['label'], colnames=['predict']))  

    model.save('test.h5')
    #------------顯示混淆矩陣------------------------------------------------
    print("New Confusion Matrix:")
    df = pd.crosstab(y_Test, prediction, rownames=['label'], colnames=['predict'])
    print(df.shape)
    print(df)
    #----------------顯示成功率---------------------------------------#
    
    print('New Accuracy=',scores[1])
    #-----------------查看預測錯誤------------------------------------#

    answer="0"
    answer2="0"
    answer3="0"
    while(answer!="Quit"):
        
        answer=input('Write label number:(if you want to quit,you can write "-1") 輸入想看的標簽數字(左排):(要結束請輸入Quit)')
        if(answer=="Quit"):
            break
        answer2=input('Write predict number: 輸入此標簽預測到的數字結果(上排)')
        if((is_int(answer)) and (is_int(answer2))):
            ii = 0
            timessss = 0
            timessss=prediction.size
            print("正確答案為:"+str(answer)+"但是判斷為:"+str(answer2)+"的代碼為如下:")
            while(ii<timessss):
                if (y_Test[ii]==int(answer))and(prediction[ii]==int(answer2)):
                    print(ii)                    
                ii+=1
            answer3="0"
            while(answer3!="-1"):
                print("輸入代碼預覽圖片與其路徑:(要回上一步請輸入-1)")
                answer3=input('Write index number to show picture:(if you want to quit,you can write "-1")')
                if((is_int(answer3))):
                    print("代碼為"+answer3+"的圖片與路徑:")
                    img=mpimg.imread(X_testFname[int(answer3)])
                    plt.imshow(img)
                    plt.show()
                 #   plot_images_labels_prediction(X_Test, y_Test, prediction, idx=int(answer3), num=1)
                    print(X_testFname[int(answer3)])
        print(df)
    #------------------------------------------------------------------------#



# if __name__=='__main__':
main()
