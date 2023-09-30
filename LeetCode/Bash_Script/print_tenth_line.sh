# Read from the file file.txt and output the tenth line to stdout.
#!/bin/bash
n=0
while read line
do
        ((n++))
        if [ $n -eq 10 ]; then
                echo $line
        fi
done < file.txt
