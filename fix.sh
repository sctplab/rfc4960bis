sed -e 's/FORMFEED\[Page/        \[Page/' $* | ./pg -n 5
