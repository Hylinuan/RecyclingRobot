# https://blog.csdn.net/tMb8Z9Vdm66wH68VX1/article/details/81713585
from keras.preprocessing.image import img_to_array
from keras.models import load_model
import numpy as np
import argparse
import imutils
import pickle
import cv2
import subprocess

def classification():
	# construct the argument parse and parse the arguments
	ap = argparse.ArgumentParser()
	ap.add_argument("-m", "--models", required=True, help="path to trained model model")
	ap.add_argument("-l", "--labelbin", required=True, help="path to label binarizer")
	ap.add_argument("-i", "--image", required=True, help="path to label binarizer")
	args = vars(ap.parse_args())
	lb = pickle.loads(open(args["labelbin"], "rb").read())

	# classify the input image
	print("[INFO] classifying image...")
	# build the label and draw the label on )
	proba = model.predict(image)[0]
	idx = np.argmax(proba)
	label = lb.classes_[idx]

	# os.system("python3 classify.py --image ", image_path)
	# args = vars(ap.parse_args())

	# load image
	image = cv2.imread(args["image"])
	image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB) # add
	output = image.copy()

	# pre-process the image for classification
	image = cv2.resize(image, (32, 32))
	image = image.astype("float")/255.0
	image = img_to_array(image)
	image = np.expand_dims(image, axis=0)

	# load the trained convolutional neural network and the label 
	# binarizer
	print("[INFO] loading network...")
	model = load_model(args["model"])

	# we'll mark our prediction as "correct" of the input image filename
	# contains the predicted label text (obviously this makes the assuption that you have named your testing image files this way)
	# filename = args["image"][args["image"]].rfind(os.path.sep) + 1:]
	# correct = "correct" if filename.rfind(label) != -1 else "incorrect" the image
	label = "{}:  {:.2f}%".format(label, proba[idx]*100)# , correct)
	output = imutils.resize(output, width = 400)
	cv2.putText(output, label, (10, 25), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)

	# show the output image
	print("{}".format(label))
	# cv2.imshow("Output", output)

	
