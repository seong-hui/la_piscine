#!/bin/sh
ifconfig | awk '/ether /' | awk '{print $2}'
