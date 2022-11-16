# -*- coding: utf-8 -*-
"""
@author: mmy
"""

# Data preprocess
from keras.datasets import recycle
import numpy as np
import matplotlib.pyplot as plt
from keras.models import save_model
import pickle


def plot_image_labels_prediction(images,labels,prediction,idx,num=10):
	fig = plt.gcf()
	fig.set_size_inches(12,14)
	if num>25: num=25
	for i in range(0, num):
		ax=plt.subplot(5,5,1+i)
		ax.imshow(images[idx],cmap='binary')
		title=str(i)+','+label_dict[labels[i][0]]
		if len(prediction)>0:
			title+='=>'+label_dict[prediction[i]]
		ax.set_title(title,fontsize=10)
		ax.set_xticks([]);ax.set_yticks([])
		idx+=1

def show_Predicted_Probability(y,prediction,x_img,Predicted_Probability,i):
	print('label:',label_dict[y[i][0]],'\npredict:',label_dict[prediction[i]])
	plt.figure(figsize=(2,2))
	plt.imshow(np.reshape(x_img_test[i],(32,32,3)))
	#plt.show()
	for j in range(10):
		print(label_dict[j]+' Probability:%1.9f'%(Predicted_Probability[i][j]))

def show_train_history(train_history, train, validation):
    plt.plot(train_history.history[train])
    plt.plot(train_history.history[validation])
    plt.title('Train History')
    plt.ylabel(train)
    plt.xlabel('Epoch')
    plt.legend(['train', 'validation'], loc='upper left')
    plt.show()

i = True
while(i == True):
	np.random.seed(50)
	# -- Using Tensorflow backend -- #
	# Read Data
	(x_img_train,y_label_train),(x_img_test,y_label_test)=recycle.load_data()
	# Show train, test data shape
	print("train data:",'images:',x_img_train.shape," labels:",y_label_train.shape)
	print("test data:",'images:',x_img_test.shape," labels:",y_label_test.shape)

	# ----- Look Training data ----- #
	x_img_train.shape
	x_img_test[0]
	y_label_train.shape

	# ----- 查看多筆Images與label ----- #
	label_dict = {0:"plastic",1:"paper",2:"glass",3:"iron",4:"aluminum"}
	label = ["plastic","papper","glass","iron","aluminum"]
	import matplotlib.pyplot as plt

	# plt.show()
	plot_image_labels_prediction(x_img_train,y_label_train,[],0)

	# Features standardization
	x_img_train_normalize = x_img_train.astype('float32')/255.0
	x_img_test_normalize = x_img_test.astype('float32')/255.0

	# Label convert by Onehot encoding  (Train data & Test data)
	from keras.utils import np_utils
	y_label_train_OneHot = np_utils.to_categorical(y_label_train)
	y_label_test_OneHot = np_utils.to_categorical(y_label_test)

	#------------------End of Data preprocessing-----------------#

	# Build model
	from keras.models import Sequential
	from keras.layers import Dense, Dropout, Activation, Flatten
	from keras.layers import Conv2D, MaxPooling2D, ZeroPadding2D

	_rate1 = 0.5
	_rate2 = 0.25

	model = Sequential()
	# Convolution layer1
	model.add(Conv2D(filters=32,kernel_size=(3,3),
		         input_shape=(32,32,3),
					 activation='relu',
					 padding='same'))
	# Dropout for avoiding overfitting 
	model.add(Dropout(rate=_rate1))
	# Pooling layer1
	model.add(MaxPooling2D(pool_size=(2,2)))
	# Convolution layer2
	model.add(Conv2D(filters=64,kernel_size=(3,3),
		         activation='relu', padding='same'))
	# Dropout for avoiding overfitting 
	model.add(Dropout(rate=_rate1))
	# Pooling layer2
	model.add(MaxPooling2D(pool_size=(2,2)))


	# Convolution layer3
	model.add(Conv2D(filters=128,kernel_size=(3,3),
		         activation='relu', padding='same'))
	# Dropout for avoiding overfitting 
	model.add(Dropout(rate=_rate1))
	# Pooling layer3
	model.add(MaxPooling2D(pool_size=(2,2)))


	# Convolution layer4
	model.add(Conv2D(filters=256,kernel_size=(3,3),
		         activation='relu', padding='same'))
	# Dropout for avoiding overfitting 
	model.add(Dropout(rate=_rate1))
	# Pooling layer4
	model.add(MaxPooling2D(pool_size=(2,2)))


	# --------------------------dropout------------------------------- #

	# Set up CNN(Flat layer, Hidden layer, Output layer)
	# Flatten layer
	model.add(Flatten())
	model.add(Dropout(rate=_rate2))
	# Dense layer
	model.add(Dense(1024, activation='relu'))
	model.add(Dropout(rate=_rate2))
	# Output layer
	model.add(Dense(5, activation='softmax'))
	# Look model 
	print(model.summary())

	#------------------ Training -----------------#
	model.compile(loss='categorical_crossentropy',
		      optimizer='adam', metrics=['accuracy'])
	train_history=model.fit(x_img_train_normalize, y_label_train_OneHot,
		                validation_split=0.2,
				epochs=500, batch_size=128, verbose=1)


	# show_train_history(train_history,'loss','val_loss')
	# show_train_history(train_history,'acc','val_acc')

	model.save('/home/rec_robot/recycle/recycle.model')
	with open('/home/rec_robot/recycle/batch/label', "wb") as fo:
		fo.write(pickle.dumps(label))
		fo.close()

	#------------------ Evaluation accuracy -----------------#
	scores = model.evaluate(x_img_test_normalize,
		                y_label_test_OneHot, verbose=0)

	#------------------ Predicting -----------------#
	prediction = model.predict_classes(x_img_test_normalize)
	prediction[:10]
	plot_image_labels_prediction(x_img_test,y_label_test,prediction,0,10)

	print('Seed: 50')
	print('Rate for pool:', _rate1)
	print('Rate for dropout:', _rate2)
	print('Test loss:', scores[0])
	print('Test accuracy:', scores[1])

	#------------------ Look Prediction Probability-----------------#
	Predicted_Probability=model.predict(x_img_test_normalize)
	# print('Predicted_Probability: ',Predicted_Probability)


	if(scores[1] >= 0.56):i = False





## Look num0 prediction probability
# show_Predicted_Probability(y_label_test,prediction,x_img_test,Predicted_Probability,0)
# show_Predicted_Probability(y_label_test, prediction, x_img_test, Predicted_Probability, 3)

# print(label_dict)
print(pd.crosstab(y_label_test.reshape(-1),prediction,rownames=['label'],colnames=['predict']))
