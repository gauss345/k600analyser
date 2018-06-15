#!/bin/bash


#load odb
#odbedit -l odb_files/odb_1WE.odb
echo "save current obd file and load accurate odb file  odb_files/odb_1WE.odb"
echo "!!! CAUTION!!! USING U1U2"



#place link for configfile
rm config.cfg
ln -s config_files/config_1WE.cfg config.cfg

#place links to calblelengthfile
rm CableLength.dat
ln -s CableLength/CableLength_1WE.dat CableLength.dat

#place links for lut
rm lut-x1.dat
rm lut-x2.dat
rm lut-u1.dat
rm lut-u2.dat

ln -s lut/lut-x1_WE1.dat lut-x1.dat
ln -s lut/lut-x2_WE1.dat lut-x2.dat
ln -s lut/lut-u1_WE1.dat lut-u1.dat
ln -s lut/lut-u2_WE1.dat lut-u2.dat



