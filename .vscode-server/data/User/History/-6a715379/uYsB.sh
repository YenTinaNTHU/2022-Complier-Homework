make
golden_scanner < ./scoring_testcase/key_ident.txt > golden_ans.txt
./scanner < ./scoring_testcase/key_ident.txt > ans.txt
diff golden_ans.txt ans.txt 
make clean