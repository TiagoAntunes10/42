#!/bin/sh
ifconfig -a | grep -oE "..:..:..:..:..:.."
