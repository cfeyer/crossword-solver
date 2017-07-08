#!/bin/bash

export COMPONENT_ROOT=${PWD}

cd ${COMPONENT_ROOT}/src
make

cd ${COMPONENT_ROOT}/tests
make

