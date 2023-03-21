files=$(grep usleep\( -R ./ --files-with-matches)
for file in $files
do
    echo " 找到含有usleep函数的文件$file"
    if cat $file | grep "#include<unistd.h>" > /dev/null
    then
        echo "文件$file中已经有#include<unistd.h>了!"
        
    else
        echo "文件$file中还没有#include<unistd.h>!"
		sed  -i "1i#include<unistd.h>" $file
		echo "add '#include<unistd.h>' in file $file successfully!"
    fi
done
