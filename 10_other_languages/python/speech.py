#!/usr/bin/env python3

import speech_recognition as sr

r = sr.Recognizer()

with sr.Microphone() as source:
    print('Speak anything: ')
    audio = r.listen(source)

    try:
        text = r.recognize_google(audio)
        print('You said : {}'.format(text))
    except:
        print('Sorry could not recognize ')
        

# Needs python3-SpeechRecognition package
# How do I use it with an audio file of a video?
