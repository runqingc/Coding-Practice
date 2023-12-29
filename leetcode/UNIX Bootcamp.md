# UNIX Bootcamp



## 1. starting ssh session

```sh
Last login: Thu Sep 14 09:58:26 on ttys000
cairunqing@cairunqingdeMacBook-Pro ~ % ssh runqingc@linux.cs.uchicago.edu
The authenticity of host 'linux.cs.uchicago.edu (128.135.164.171)' can't be established.
ED25519 key fingerprint is SHA256:y6BNPmKUOddYPcg/qSU3iEyb6CzgW4zXPtq0lH/iRRo.
This key is not known by any other names
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added 'linux.cs.uchicago.edu' (ED25519) to the list of known hosts.
runqingc@linux.cs.uchicago.edu's password: 


This system runs Ubuntu 20.04

For long running jobs please consider using the Slurm cluster `Peanut`.

  https://howto.cs.uchicago.edu/slurm:peanut

Questions:
  techstaff@cs.uchicago.edu
  Discord: https://discord.gg/ZVjX8Gv

- Techstaff



The programs included with the Ubuntu system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Ubuntu comes with ABSOLUTELY NO WARRANTY, to the extent permitted by
applicable law.

runqingc@linux1:~$ 

```



## 2. entering text

shortcut

[]

date:

```sh
runqingc@linux1:~$ date
Thu 14 Sep 2023 10:58:44 AM CDT
runqingc@linux1:~$ cal
   September 2023     
Su Mo Tu We Th Fr Sa  
                1  2  
 3  4  5  6  7  8  9  
10 11 12 13 14 15 16  
17 18 19 20 21 22 23  
24 25 26 27 28 29 30  
                      
runqingc@linux1:~$ 
```

copy

 []



## 3. file system



### paths

root directory

[]



standard directories

[]



* path name

[]



* absolute path name

[]

```sh
/home/his/bin/log
```

route from home to target

* relative path

route from where I am to target

```sh
./bin/log
```

first dot means the current directory



### navigate

``.`` current directory

``..``  parent directory

```sh
runqingc@linux1:/home/zw39$ cd ..
runqingc@linux1:/home$ 
```

``~`` short cut to home

```sh
runqingc@linux1:/home$ cd ~runqingc
runqingc@linux1:~$ pwd
/home/runqingc
```

find home directory

```sh
runqingc@linux1:~$ ~runqingc
-bash: /home/runqingc: Is a directory
```



show current directory

```sh
runqingc@linux1:~$ pwd
/home/runqingc
```



``ls`` list directory contents

```sh
runqingc@linux1:~$ ls /home/runqingc
Desktop  Documents  Downloads  Music  Pictures  Public  Templates  Videos
```

ls[]

ls -l

```sh
cairunqing@cairunqingdeMacBook-Pro Web % ls -l
total 1712
-rwxrwxrwx   1 cairunqing  staff       0  2 28  2023 2.28 html prac
-rwxrwxrwx   1 cairunqing  staff    4641  3 10  2023 2.28 html prac.html
-rwxrwxrwx   1 cairunqing  staff    1029  3 10  2023 CSS_intro.html
drwxr-xr-x@ 13 cairunqing  staff     416  9 11 09:35 L10 Flexbox_And_Responsive
drwxr-xr-x@  5 cairunqing  staff     160  9 13 08:12 L11 PricingPanel
drwxr-xr-x   6 cairunqing  staff     192  7 24 23:53 L14 JS Basic
drwxr-xr-x   3 cairunqing  staff      96  7 12 02:14 L15 JS String
```

show all, even if hidden

```sh
cairunqing@cairunqingdeMacBook-Pro Web % ls -a
```

t

cd

[]

[]

```sh
runqingc@linux1:~$ cd /home
runqingc@linux1:/home$ cd /home/runqingc
runqingc@linux1:~$ pwd
/home/runqingc
```



copy path name on mac

```sh
cmd+opt+C
```

if name have space

```sh
cairunqing@cairunqingdeMacBook-Pro Web % cd "L16 JS Decision"
cairunqing@cairunqingdeMacBook-Pro L16 JS Decision % 
```

chinese will work

```sh
cairunqing@cairunqingdeMacBook-Pro Web % cd 课件
```



### create file

[]

[]

create file: 

```sh
runqingc@linux1:~/Documents$ touch bootcamp.txt
runqingc@linux1:~/Documents$ ls
bootcamp.txt
```

view: 

```sh
runqingc@linux1:~/Documents$ vim bootcamp
```

<img src="/Users/cairunqing/Library/Application Support/typora-user-images/截屏2023-09-14 11.39.00.png" alt="截屏2023-09-14 11.39.00" style="zoom:30%;" />

hit ``i`` to insert

``esc`` quit

``:wq!`` save and exit

``:q!`` do not save and exit



``mkdir``

make directory

```sh
runqingc@linux1:~/Documents$ mkdir ~/bootcamp
runqingc@linux1:~/Documents$ cd ..
runqingc@linux1:~$ ls
bootcamp  Desktop  Documents  Downloads  Music  Pictures  Public  Templates  Videos
```

```sh
runqingc@linux1:~/bootcamp$ cd Dir1
runqingc@linux1:~/bootcamp/Dir1$ mkdir A B C
runqingc@linux1:~/bootcamp/Dir1$ ls
A  B  C
```



###copy

```sh
runqingc@linux1:~/bootcamp/Dir2$ cp -r D ~/bootcamp/Dir1/A
runqingc@linux1:~/bootcamp/Dir1/A$ ls
D
```



###move

```sh
runqingc@linux1:~/bootcamp$ mv Dir1 Dir2
runqingc@linux1:~/bootcamp$ ls
Dir2
runqingc@linux1:~/bootcamp$ cd Dir2
runqingc@linux1:~/bootcamp/Dir2$ mv Dir1 ~/bootcamp/
runqingc@linux1:~/bootcamp/Dir2$ cd ..
runqingc@linux1:~/bootcamp$ ls
Dir1  Dir2
```



###rename

```sh
runqingc@linux1:~/Documents$ mv bootcamp.txt Bootcamp.txt
runqingc@linux1:~/Documents$ ls
bootcamp  Bootcamp.txt
```



### delete

```sh
runqingc@linux1:~/Documents$ ls
bootcamp  Bootcamp.txt
runqingc@linux1:~/Documents$ rm Bootcamp.txt 
runqingc@linux1:~/Documents$ ls
bootcamp
```

delete with confirmation

```sh
runqingc@linux1:~/Documents$ ls
bootcamp
runqingc@linux1:~/Documents$ rm -i bootcamp 
rm: remove regular file 'bootcamp'? y
runqingc@linux1:~/Documents$ ls
```



## 4. Get help

```sh
runqingc@linux1:~/bootcamp$ cp --help
Usage: cp [OPTION]... [-T] SOURCE DEST
  or:  cp [OPTION]... SOURCE... DIRECTORY
  or:  cp [OPTION]... -t DIRECTORY SOURCE...
```

show documentation

```sh
runqingc@linux1:~/bootcamp$ man cp
```





## 5. Input Output

[]

[]

output

```sh
runqingc@linux1:~/Documents$ cat a
apple
banana
copy
dna
```

sort

```sh
runqingc@linux1:~/Documents$ sort a.txt
runqingc@linux1:~/Documents$ cat a
apple
banana
copy
dna
```

compare

```sh
runqingc@linux1:~/Documents$ diff -y a b
apple							      |	orange
banana							      |	lettuce
copy							      |	grape
dna							      |	peach
							      >	lichi
							      >	avocado
```



#### copy file

```sh
cairunqing@cairunqingdeMacBook-Pro MSH % scp HW6* runqingc@linux5.cs.uchicago.edu:/home/runqingc/Intro_to_Unix/msh/msh-runqingc/saqs
```



```sh
cairunqing@cairunqingdeMacBook-Pro Downloads % scp -r hw6_tests runqingc@linux5.cs.uchicago.edu:/home/runqingc/Intro_to_Unix/msh/msh-runqingc/tests
```






## 6.Permission

```sh
runqingc@linux1:~/Documents$ chmod 740 a
```

self: read(4)+write(2)+execute(1)

group: read(4)

other: no permission



## 7. Link

pointer

For example, if we have a file a.txt. If we create a hard link to the file and then delete the file, we can still access the file using hard link. But if we create a soft link of the file and then delete the file, we can’t access the file through soft link and soft link becomes dangling. Basically hard link increases reference count of a location while soft links work as a shortcut (like in Windows) 

hard link: 

```sh
runqingc@linux1:~/Documents$ ln a ahlink
```

soft link: 

```sh
runqingc@linux1:~/Documents$ ln -s a alink
```

hard “深拷贝” 

soft "浅拷贝" just copied the address, when original file deleted, it will be dangling

```sh
runqingc@linux1:~/Documents$ ls
ahlink  alink  a.txt  b  b.txt
runqingc@linux1:~/Documents$ cat ahlink
apple
banana
copy
dna
```



## 8. Download

```sh
runqingc@linux1:~/Documents$ scp runqingc@linux.cs.uchicago.edu:/etc/passwd passwd_copy.txt
The authenticity of host 'linux.cs.uchicago.edu (128.135.164.171)' can't be established.
ECDSA key fingerprint is SHA256:W8rbGZbIv57nNbbtCKF7FKMoqR0Wblw6lWzrh93HiyQ.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added 'linux.cs.uchicago.edu' (ECDSA) to the list of known hosts.
Warning: the ECDSA host key for 'linux.cs.uchicago.edu' differs from the key for the IP address '128.135.164.171'
Offending key for IP in /etc/ssh/ssh_known_hosts:4
Are you sure you want to continue connecting (yes/no)? yes
runqingc@linux.cs.uchicago.edu's password: 
passwd                                                                100% 2577   746.0KB/s   00:00
```



## 9. zip

```sh
runqingc@linux1:~$ zip -r b1  bootcamp/ b1
```

[]

如何把mac上压缩的文件上传到linux?

下载到mac上？





## 10. pipeline



## 11. Mail

```sh
runqingc@linux1:~$ mail zw39@uchicago.edu
Subject: hi 
hi
Cc: 
```















