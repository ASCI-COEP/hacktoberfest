# -*- coding: utf-8 -*-
"""
Created on Mon Aug  5 23:25:26 2019

@author: Vasu
"""

import cv2

cap = cv2.VideoCapture(0)
# Get user supplied values

smileCascade = cv2.CascadeClassifier("haarcascade_smile.xml") 
faceCascade = cv2.CascadeClassifier("haarcascade_frontalface_alt.xml") 

while(1):
# Create the haar cascade
    ret, frame = cap.read()

# Read the image
    image = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    
    faces = faceCascade.detectMultiScale(
            image,
            scaleFactor=1.3,
            minNeighbors=5,
            minSize=(30, 30),
            #flags = cv2.cv.CV_HAAR_SCALE_IMAGE
            )
    print("Found {0} faces!".format(len(faces)))
    

# Detect smiles in the faces
    for (x,y,w,h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
        face = image[y:y+h,x:x+w]
        roi_color = frame[y:y+h,x:x+w]
        
        smiles = smileCascade.detectMultiScale(face,1.3,17.5)
        
        for (sx, sy, sw, sh) in smiles:
            cv2.rectangle(roi_color, (sx, sy), (sx+sw, sy+sh), (255, 0, 0), 2)
            font = cv2.FONT_HERSHEY_SIMPLEX
            color = (0,0,255)
            stroke = 2
            cv2.putText(frame,"SMILING",(x,y),font,0.7,color,stroke,cv2.LINE_AA)
        print("Found {0} smiles!".format(len(smiles)))
    
    # Draw a rectangle around the faces
    
        
        
    cv2.imshow('frame', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    
cap.release()
cv2.destroyAllWindows()