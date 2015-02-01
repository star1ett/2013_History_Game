/*
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0
*/

int firstmap[][10][10]={
	{
		1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,1,1,0,1,0,1,
		1,1,1,0,0,0,0,1,0,1,
		1,0,0,0,1,1,0,0,0,1,
		1,0,1,0,0,1,1,1,0,0,
		1,0,1,1,0,1,0,1,0,1,
		1,0,1,0,0,0,0,1,0,1,
		1,0,1,1,1,1,1,1,0,1,
		1,0,0,0,0,0,0,1,0,1,
		1,1,1,1,0,1,1,1,1,1
	},{
		1,1,1,1,1,1,1,1,1,1,
		1,0,1,0,1,0,0,0,0,1,
		1,0,1,0,1,1,1,1,0,1,
		1,0,0,0,0,1,0,1,0,1,
		1,0,1,1,1,1,0,0,0,0,
		1,0,1,0,0,0,1,1,0,1,
		1,0,0,0,1,0,0,1,0,1,
		1,0,1,1,1,1,0,1,0,1,
		1,0,1,0,0,0,0,0,0,1,
		1,1,1,1,0,1,1,1,1,1
	},{
		1,1,1,1,1,1,1,1,1,1,
		1,0,1,0,0,0,1,1,1,1,
		1,0,0,0,1,0,0,0,0,1,
		1,0,1,0,1,1,1,1,0,1,
		1,0,1,0,0,1,0,1,0,0,
		1,0,1,1,1,1,0,1,0,1,
		1,0,0,0,0,0,0,1,0,1,
		1,0,1,1,1,1,1,1,0,1,
		1,0,0,0,0,0,0,1,0,1,
		1,1,1,1,0,1,1,1,1,1,
	},{
		1,1,1,1,1,1,1,1,1,1,
		1,0,1,0,0,1,0,0,0,1,
		1,0,1,1,0,0,0,1,0,1,
		1,0,0,0,0,1,1,1,1,1,
		1,0,1,1,0,1,0,1,0,0,
		1,0,0,1,0,0,0,1,0,1,
		1,1,0,1,1,1,0,1,0,1,
		1,0,0,0,0,1,0,1,0,1,
		1,0,1,1,0,1,0,0,0,1,
		1,1,1,1,0,1,1,1,1,1
	},{
		1,1,1,1,1,1,1,1,1,1,
		1,0,1,0,0,0,0,0,0,1,
		1,0,1,0,1,1,1,1,0,1,
		1,0,1,0,1,0,0,1,1,1,
		1,0,1,0,0,0,1,1,0,0,
		1,0,0,0,1,0,1,1,0,1,
		1,0,1,1,1,0,0,1,0,1,
		1,0,0,0,1,1,0,1,0,1,
		1,0,1,0,0,1,0,0,0,1,
		1,1,1,1,0,1,1,1,1,1
	},{
		1,1,1,1,1,1,1,1,1,1,
		1,0,1,0,0,0,0,0,0,1,
		1,0,0,0,1,0,1,1,0,1,
		1,1,1,1,1,0,1,0,0,1,
		1,0,0,0,1,0,1,1,0,0,
		1,0,1,0,1,0,0,1,1,1,
		1,0,1,1,1,1,0,1,0,1,
		1,0,0,0,0,1,0,1,0,1,
		1,1,0,1,0,0,0,0,0,1,
		1,1,1,1,0,1,1,1,1,1
	},{
		1,1,1,1,1,1,1,1,1,1,
		1,0,1,0,0,0,1,0,1,1,
		1,0,1,0,1,0,0,0,0,1,
		1,0,1,0,1,1,1,1,0,1,
		1,0,1,0,1,0,0,0,0,0,
		1,0,0,0,1,0,1,1,1,1,
		1,0,1,0,1,0,0,0,0,1,	
		1,0,1,1,1,1,1,1,0,1,
		1,0,0,0,0,1,0,0,0,1,
		1,1,1,1,0,1,1,1,1,1
	}
};

int mainmap[][10][10]={
	{
		1,0,0,0,0,0,0,0,1,1,
		0,0,1,0,1,0,1,0,0,1,
		0,1,1,1,1,1,1,1,0,1,
		0,1,0,0,0,0,0,1,1,1,
		0,0,0,1,1,1,0,0,0,0,
		0,1,1,1,0,1,1,1,0,1,
		0,0,0,0,0,0,0,1,1,1,
		1,0,1,1,1,1,0,1,0,1,
		0,0,1,0,0,0,0,0,0,1,
		1,1,1,1,0,1,1,1,1,1
	},{
		0,0,1,1,0,1,0,0,0,1,
		1,0,0,0,0,0,0,1,0,1,
		0,0,1,1,1,1,1,1,0,1,
		0,1,1,0,0,0,0,1,0,1,
		0,0,0,0,1,1,0,1,0,0,
		0,1,1,1,1,0,0,1,0,1,
		0,1,0,0,0,0,1,1,0,1,
		1,1,1,0,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,0,1,
		0,1,1,1,0,1,1,1,1,1
	},{
		0,0,0,1,0,0,0,1,0,1,
		0,1,0,0,0,1,0,1,0,1,
		0,1,1,1,1,1,0,0,0,1,
		0,0,0,0,0,1,1,1,0,1,
		0,1,1,1,0,0,0,1,0,0,
		0,0,0,1,1,1,0,1,1,1,
		0,1,0,1,0,1,0,0,0,1,
		1,1,0,1,0,1,1,1,0,1,
		0,0,0,0,0,1,0,0,0,1,
		1,1,1,1,0,1,1,1,1,1
	},{
		1,0,0,0,0,1,0,0,0,1,
		0,0,1,0,1,1,0,1,0,1,
		0,1,1,0,1,0,0,1,0,1,
		1,1,0,0,1,0,1,1,0,1,
		0,1,0,1,1,0,1,0,0,0,
		0,1,0,0,0,0,1,0,1,1,
		0,1,1,1,1,1,1,0,0,1,
		0,1,0,0,0,1,1,1,0,1,
		0,0,0,1,0,1,0,0,0,1,
		1,1,1,1,0,1,1,1,1,1
	},{
		1,0,1,0,0,1,0,0,0,1,
		0,0,1,0,1,1,0,1,0,1,
		0,1,1,0,1,0,0,1,0,1,
		0,0,0,0,1,0,1,1,0,1,
		0,1,0,1,1,0,1,0,0,0,
		0,1,0,0,0,0,1,0,1,1,
		0,1,1,1,1,1,1,0,0,1,
		0,1,0,0,0,0,0,1,0,1,
		0,0,0,1,0,1,0,1,0,1,
		1,1,1,1,0,1,1,1,1,1
	},{
		0,0,1,0,0,0,0,0,0,1,
		0,1,1,0,1,1,1,1,0,1,
		0,0,1,0,1,0,0,0,0,1,
		0,1,1,0,1,1,0,1,1,1,
		0,0,0,1,1,1,0,1,0,0,
		0,1,0,0,0,0,0,1,0,1,
		0,1,1,1,0,1,0,1,0,1,
		0,1,0,1,1,1,0,1,0,1,
		0,0,0,1,0,0,0,0,0,1,
		1,1,1,1,0,1,1,1,1,1
	},{
		0,0,0,0,0,0,1,0,0,1,
		1,0,1,0,1,1,1,1,0,1,
		0,0,1,1,1,0,0,0,0,1,
		0,1,1,0,1,1,0,1,1,1,
		0,0,0,0,0,1,0,1,0,0,
		1,1,0,1,0,0,0,1,0,1,
		0,0,0,1,0,1,0,1,0,1,
		0,1,1,1,1,1,0,1,0,1,
		0,0,0,1,0,0,0,0,0,1,
		1,1,1,1,0,1,1,1,1,1
	},{
		0,0,1,1,0,1,0,0,0,1,
		1,0,1,0,0,0,0,1,0,1,
		0,0,1,0,1,1,1,1,0,1,
		0,1,1,0,0,0,1,1,1,1,
		0,0,0,0,1,0,0,1,0,0,
		1,1,1,1,1,1,0,1,0,1,
		0,0,0,0,0,0,0,0,0,1,
		0,1,1,1,1,0,1,1,1,1,
		0,0,0,1,0,0,0,0,0,1,
		1,1,1,1,0,1,1,1,1,1
	}
};

int lastmap[][10][10]={
	{
		0,1,1,1,0,1,0,0,0,1,
		0,0,0,1,0,0,0,1,1,1,
		1,0,1,1,1,1,0,1,0,1,
		1,0,1,0,0,1,0,0,0,1,
		0,0,1,0,1,1,0,1,0,1,
		1,0,1,0,0,1,1,1,0,1,
		0,0,1,0,1,0,0,0,0,1,
		0,1,1,0,1,0,1,1,0,1,
		0,0,0,0,0,0,0,1,0,1,
		1,1,1,1,1,1,1,1,1,1
	},{
		0,0,0,0,0,1,0,0,0,1,
		0,1,1,1,0,0,0,1,0,1,
		0,0,1,0,0,1,1,1,0,1,
		1,0,1,1,1,1,0,1,0,1,
		0,0,1,0,0,0,0,0,0,1,
		1,1,1,0,1,1,1,1,1,1,
		0,0,0,0,1,0,0,0,0,1,
		0,1,1,0,0,0,1,1,0,1,
		0,0,1,1,1,0,0,1,0,1,
		1,1,1,1,1,1,1,1,1,1
	},{
		0,0,0,1,0,1,1,0,1,1,
		0,1,0,0,0,0,0,0,0,1,
		0,0,1,0,1,1,1,1,0,1,
		1,0,1,1,0,0,0,0,0,1,
		0,0,0,1,0,1,0,1,1,1,
		1,1,0,1,0,1,0,0,0,1,
		0,0,0,1,1,1,1,1,0,1,
		0,1,1,1,0,0,0,1,0,1,
		0,0,0,0,0,1,0,1,0,1,
		1,1,1,1,1,1,1,1,1,1
	}/*,{
		0,0,0,1,0,1,0,0,0,1,
		0,0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1
	},{
		1,1,1,1,0,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1
	},{
		1,1,1,1,0,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1
	}*/
};