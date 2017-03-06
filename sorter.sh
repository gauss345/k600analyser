#!/bin/bash

#for COUNT in {1069,1070,1071,1072,1076,1077,1078,1082,1084,1085,1087,1088,1090,1091,1092,1093,1098,1099,1100}
for COUNT in {1084,1087,1088,1092,1093}

do
  echo $COUNT
  if [ $COUNT -lt 10 ]
  then
      FILE="/experiment-data/PR251/2016/run0000"$COUNT".mid.gz"
  elif [ $COUNT -lt 100 ]
  then
      FILE="/experiment-data/PR251/2016/run000"$COUNT".mid.gz"
  elif [ $COUNT -lt 1000 ]
  then
      FILE="/experiment-data/PR251/2016/run00"$COUNT".mid.gz"
  elif [ $COUNT -lt 10000 ]
  then
      FILE="/experiment-data/PR251/2016/run0"$COUNT".mid.gz"
  elif [ $COUNT -lt 100000 ]
  then
      FILE="/experiment-data/PR251/2016/run"$COUNT".mid.gz"
  else
      echo "This might not work"
  fi
  echo $FILE
  if [ $COUNT -lt 10 ]
  then
#      FILE2="/vicepda/althome/k600user/PR251/2016/sortedfiles/sorted0000"$COUNT".root"
      FILE2="../sortedfiles/sorted0000"$COUNT".root"
  elif [ $COUNT -lt 100 ]
  then
#      FILE2="/vicepda/althome/k600user/PR251/2016/sortedfiles/sorted000"$COUNT".root"
      FILE2="../sortedfiles/sorted000"$COUNT".root"
  elif [ $COUNT -lt 1000 ]
  then
#      FILE2="/vicepda/althome/k600user/PR251/2016/sortedfiles/sorted00"$COUNT".root"
      FILE2="../sortedfiles/sorted00"$COUNT".root"
  elif [ $COUNT -lt 10000 ]
  then
#      FILE2="/vicepda/althome/k600user/PR251/2016/sortedfiles/sorted0"$COUNT".root"
      FILE2="../sortedfiles/sorted0"$COUNT".root"
  elif [ $COUNT -lt 100000 ]
  then
#      FILE2="/vicepda/althome/k600user/PR251/2016/sortedfiles/sorted"$COUNT".root"
      FILE2="../sortedfiles/sorted"$COUNT".root"
  else
      echo "This might not work"
  fi
  echo $FILE2
  if [ -e $FILE ]
  then
      if [ ! -e $FILE2 ]
      then
      echo $FILE
      ./analyzer -i $FILE
      mv output.root $FILE2
      fi
  fi
done
