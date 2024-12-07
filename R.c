void R();

// RRRRRRRRRRRRRRRRRRRRRRRR
    if(optTable[OPT__R_])
    {
        R(filepath[0]);
        return 0;
    }
    // RRRRRRRRRRRRRRRRRRRRRRRR

void R(char * Rfile)
{
    
    struct ifm * Rlist = (struct ifm *)malloc(sizeof(struct ifm) * 20000000);

    DIR * rdir = opendir(Rfile);
    if(rdir == NULL)
    {
        fprintf(stderr,"\033[0m""ls: 无法打开目录 '%s': 权限不够\n",Rfile);
        return;
    }   
    int count4q = 0;
    struct dirent * trdir;
    for(int i = 0;(trdir = readdir(rdir))!=NULL;i++,count4q++)
    {
        char temp[2000];
        Rlist[i].rdirent = *trdir;
        sprintf(temp,"%s/%s",Rfile,Rlist[i].rdirent.d_name);
        stat(temp,&Rlist[i].buf__stat);
    }
    qsort(Rlist,count4q,sizeof(struct ifm),sort_init);
    printf("%s:\n\n",Rfile);
    for(int i = 0;i<count4q;i++)
    {
        if(!optTable[OPT__a_])
        {
            if(*Rlist[i].rdirent.d_name=='.')
                continue;
        }
        if(optTable[OPT__l_])
        {
        // 第一列
            if(S_ISDIR(Rlist[i].buf__stat.st_mode))printf("d");
            else if(S_ISLNK(Rlist[i].buf__stat.st_mode))printf("l");
            else if(S_ISBLK(Rlist[i].buf__stat.st_mode))printf("d");
            else if(S_ISCHR(Rlist[i].buf__stat.st_mode))printf("c");
            else if(S_ISCHR(Rlist[i].buf__stat.st_mode))printf("c");
            else printf("-");

            // 所有者权限
            printf(Rlist[i].buf__stat.st_mode & S_IRUSR?"r":"-");
            printf(Rlist[i].buf__stat.st_mode & S_IWUSR?"w":"-");
            printf(Rlist[i].buf__stat.st_mode & S_IXUSR?"x":"-");
            //所属组权限
            printf(Rlist[i].buf__stat.st_mode & S_IRGRP?"r":"-");
            printf(Rlist[i].buf__stat.st_mode & S_IWGRP?"w":"-");
            printf(Rlist[i].buf__stat.st_mode & S_IXGRP?"x":"-");

            //其他用户权限
            printf(Rlist[i].buf__stat.st_mode & S_IROTH?"r":"-");
            printf(Rlist[i].buf__stat.st_mode & S_IWOTH?"w":"-");
            printf(Rlist[i].buf__stat.st_mode & S_IXOTH?"x":"-");

            printf(" %lu",Rlist[i].buf__stat.st_nlink);
            printf(" %s",getpwuid(Rlist[i].buf__stat.st_uid)->pw_name);
            printf(" %s",getgrgid(Rlist[i].buf__stat.st_gid)->gr_name);
            printf("%lu ",Rlist[i].buf__stat.st_size);
            
            struct tm * time = localtime(&Rlist[i].buf__stat.st_mtime);
            char time_buf[64];
            strftime(time_buf, 64, "%m月 %d %H:%M",time);
            printf("%s ",time_buf);
        }

        if(S_ISDIR(Rlist[i].buf__stat.st_mode))
        {
            printf("\033[1;5;34m""%s\n\033[0m",Rlist[i].rdirent.d_name);
        }
        else if(Rlist[i].buf__stat.st_mode&S_IXUSR)
        {
            printf("\033[1;5;32m""%s\n\033[0m",Rlist[i].rdirent.d_name);
        }
        else if(strstr(Rlist[i].rdirent.d_name,".png")!=NULL)
        {
            printf("\033[1;5;35m""%s\n\033[0m",Rlist[i].rdirent.d_name);
        }
        else 
        {
            printf("%s\n",Rlist[i].rdirent.d_name);
        }
        
    }

    for(int i = 0;i<count4q;i++)
    {
        if(S_ISDIR(Rlist[i].buf__stat.st_mode)&&strcmp(Rlist[i].rdirent.d_name, ".") != 0 && strcmp(Rlist[i].rdirent.d_name, "..") != 0)
        {
            char go[1000];
            sprintf(go,"%s/%s",Rfile,Rlist[i].rdirent.d_name);
            struct stat ng;
            
            lstat(go,&ng);
            
            if(ng.st_mode==-1)
                exit(1);

            if(S_ISLNK(ng.st_mode))
            {
                continue;
            }
            
            R(go);
        }
    }
    free(Rlist);
}