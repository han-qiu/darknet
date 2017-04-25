#!/bin/bash
curl -O https://pjreddie.com/media/files/VOCtrainval_11-May-2012.tar && \
curl -O https://pjreddie.com/media/files/VOCtrainval_06-Nov-2007.tar && \
curl -O https://pjreddie.com/media/files/VOCtest_06-Nov-2007.tar && \
tar xf VOCtrainval_11-May-2012.tar && \
tar xf VOCtrainval_06-Nov-2007.tar && \
tar xf VOCtest_06-Nov-2007.tar
python scripts/voc_label.py
cat 2007_train.txt 2007_val.txt 2012_*.txt > train.txt
cp 2007_test.txt data/voc.2007.test
