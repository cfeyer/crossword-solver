#!/bin/bash

export COMPONENT_ROOT=${PWD}

rm bin/*
rm lib/*

cd ${COMPONENT_ROOT}/src
make clean

cd ${COMPONENT_ROOT}/tests
make clean


