void traverse(){
	int temp;
	if(front==-1){
		printf("Stack is Empty.");
		return;
	}
	temp=front;
	if(temp>rear){
	while(temp>=(rear+1)%MAX){
		printf("| %d |",queue[temp]);

		temp=(temp+1)%MAX;
		}
	if(temp<=rear){
		while(temp<=rear){
			printf("| %d |",queue[temp]);
			temp=temp+1;
		}
	}
}
	if(temp<rear){
		while(temp<=rear){
			printf("| %d |",queue[temp]);
			temp=temp+1;
		}
	}
}
