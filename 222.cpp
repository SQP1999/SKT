	if(input == 'k')
	{
			if(in_pause==0){
				in_pause = 1;
				while(1){
					if(getch()=='k'){
						in_pause = 0;
						break;
					}
				}
			}
		}
