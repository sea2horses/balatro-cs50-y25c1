#!bin/bash

rm balatro -r -fv
mkdir balatro
cp balatro_template.c balatro/balatro.c
rm balatro.zip -fv
zip balatro.zip balatro/ -r
