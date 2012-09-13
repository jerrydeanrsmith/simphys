#!/bin/bash

# Assuming that you're already in the grader's directory
# with the student's implementation in the right place,
# build the code and run the tests.
function buildAndRun {
  mkdir build
  cd build
  cmake .. > /dev/null
  make > /dev/null
  echo -e "\t" $1 ":" `../bin/tests | tail -1`
}

for package in $( ls ); do
  if [ `echo $package | grep tar` ]; then
    # parse the file name
    file=(`echo $package | tr '-' ' '`)
    echo Grading assignment for ${file[0]} ${file[1]}
    name=${file[0]}-${file[1]}
    mkdir $name
    cp $package $name
    cd $name

    # unpackage tar
    tar -xf $package
    rm $package

    case `ls` in
    "vec3.cpp")
      cp -rf ../quiz1grading .
      cp vec3.cpp quiz1grading/src/main
      cd quiz1grading
      buildAndRun $name
      cd ../..
      ;;

    "main")
      cp -rf ../quiz1grading .
      cp ./main/vec3.cpp quiz1grading/src/main
      cd quiz1grading
      buildAndRun $name
      cd ../..
      ;;

    "src")
      cp -rf ../quiz1grading .
      cp src/main/vec3.cpp quiz1grading/src/main
      cd quiz1grading
      buildAndRun $name
      cd ../..
      ;;

    "quiz1")
      cp -rf ../quiz1grading .
      cp quiz1/src/main/vec3.cpp quiz1grading/src/main
      cd quiz1grading
      buildAndRun $name
      cd ../..
      ;;

    *)
      echo -e "\tGot something else."
      ;;
    esac
    cd ..
  fi
done