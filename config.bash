#!/bin/bash

export COMPONENT_ROOT=${PWD}
export PATH="${PATH}:${COMPONENT_ROOT}/bin"
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${COMPONENT_ROOT}/lib"
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:/usr/local/lib"

