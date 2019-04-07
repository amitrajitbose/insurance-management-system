class Policy
{
public:
    int type;
    double final_premium;
    int date[3];
    double healthInsurance(int age)
    {
        //returns total premium.
        
        //policy start date store
        
        double prem,ci_prem,tot_prem;
        int health_condition, policy_period, sum;
        cout<<"Enter Health Condition (0 to 10) with 10 being the Fittest.:";
        cin>>health_condition;
        cout<<"Enter Policy period (in months): ";
        cin>>policy_period;
        cout<<"Sum Chart = ";
        cout<<"1,2,3,4,5 (in Lakhs)\n"; 
        cout<<"Enter Sum Insured: "<<endl;
        cin>>sum;
        
        
        int prem_age[6][5]= {{1802,2689,3362,4168,4572},
                            {2226,3213,4016,4980,5462},
                            {2286,3253,4116,4985,5862},
                            {4125, 5319,6648,8244,9042},
                            {5749,8681, 10852,13456,14758},
                            {13308,20097,25121,31150,34164}};
                            
        int ci_prem_age[6][5]={{31,61,92,122,153},
                            {116,231,347,462,578},
                            {354,706,1062,1415,1769},
                            {776, 1552,2348,2911,3889},
                            {1279,2557,3836,5114,6383},
                            {2008,4040,6025,8050,10341}};
        
        double fit_age[10]={0,0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8};

        
        if(age<=17)
        {
            prem=prem_age[0][sum-1];
            ci_prem=ci_prem_age[0][sum-1];
        }
        else if(age >=18 && age<=35)
        {
            prem = prem_age[1][sum-1];
            ci_prem=ci_prem_age[1][sum-1];
        }
        else if(age >=36 && age<=49)
        {
            prem = prem_age[2][sum-1];
            ci_prem=ci_prem_age[2][sum-1];
        }
        else if (age >=50 && age<=65 )
        {
            prem = prem_age[3][sum-1];
            ci_prem=ci_prem_age[3][sum-1];
        }
        else if(age >=66 && age<=75 )
        {
            prem = prem_age[4][sum-1];
            ci_prem=ci_prem_age[4][sum-1];
        }
        else if(age >=75 && age<=85 )
        {
            prem = prem_age[5][sum-1];
            ci_prem=ci_prem_age[5][sum-1];
        }
        else
            return 0.0;
        
        
        prem=prem-fit_age[health_condition]*prem;
        tot_prem=prem+ci_prem;
        
        //store total prem. deatils to show currentdate-startdate= months already paid. rem = (policy_period-monthspaid)
        
        cout<<"Your total premium is : "<<tot_prem<<"\t for a period of "<<policy_period<<" month(s) "<<endl;
        return tot_prem;
    }

    double lifeInsurance(int age)
    {
        //policy_period, age
        int policy_amount,term; //10 lakh to 1 crore
        double prem;
        int t=(60-age)*12;
        cout<<"Select one of the following term plans :"<<endl;
        cout<<"1 --> Monthly"<<endl;
        cout<<"2 --> Quaterly"<<endl;
        cout<<"3 --> Semi annually"<<endl;
        cout<<"4 --> Annually"<<endl;
        string termstring[4]={"monthly","quaterly","semi-annually","annually"};
        cin>>term;
        cout<<"Enter Amount within the following ranges"<<endl;
        cout<<"10 Lakh ....1 Cr. in digits:";
        cin>>policy_amount;
        if(term==1){
            cout << "Monthly...\n";
            prem = policy_amount/t;
        }
        else if(term==2){
            t=t/4;
            cout << "Quarterly...\n";
            prem = policy_amount/(t);
        } 
        else if(term==3){
            t=t/6;
            cout << "Semi...\n";
            prem = policy_amount/(t);
            
        }
        else if(term==4){
            t=t/12;
            cout << "Annually...\n";
            prem = policy_amount/(t);
            
        }
        else{
            return 0.0;
        }
        cout<<"Your "<<termstring[term-1]<<" premium is : "<<prem<<" for a period of "<<t<<" times "<<termstring[term-1]<<endl;
        return prem;
    }

    double homeInsurance(int pp,int age){
        int house_age,sqft,cost_sqft;
        char own_rent,flat_bung;
        double tot_prem,prem;
        const double dep = 0.15;

        cout<<"Is your flat rented(r) or owned(o)? ";
        cin>>own_rent;
        if(own_rent=='r')
        {
            int content_price;
            cout<<"Enter total value of contents : ";
            cin>>content_price;
            tot_prem=content_price*11; 
        }

        else
        {
        cout<<"Do you own a flat(f) or bungalow(b)? ";
        cin>>flat_bung;
        
        cout<<"Age of flat/building? ";
        cin>>house_age; 
        if(house_age<=30)
        
        {
            
            if(flat_bung=='f' )
            {
                cout<<"Enter sqft area of flat : "; 
                cin>>sqft;
                cout<<"Enter cost of construction per sqft area of flat : "; 
                cin>>cost_sqft;
                tot_prem = sqft*cost_sqft-dep*house_age;
            }
            if(flat_bung=='b' )
            {
                cout<<"Enter Built Area: "; 
                cin>>sqft;
                cout<<"Enter Cost of construction: "; 
                cin>>cost_sqft;
                tot_prem = sqft*cost_sqft-dep*house_age;
            }
        }
        else
        {
            cout<<"You Do Not Qualify for Home Insurance."<<endl;
            return 0;
        }
        }
        int m;
        if (pp!=-9)
        {
        m=  (pp*12);
        prem = tot_prem/m;
        }
        else{
            m=((70-age)*12);
            prem = tot_prem/m;
        }
        
            cout<<"Your Monthly Premium is : "<< prem <<" for a period of "<< m <<" months "<<endl;
        return prem;
    }

    void createNewPolicy(int user_token)
    {
        //if(details exist for user_token)
        //display details 
        int age,health_condition,policy_period,sum;
        
        bool flag = true;
        int policy_choice,total_premium;
        cout<<"Enter Choice Of Policy"<<endl;
        cout<<"1 --> Health Insurance"<<endl;
        cout<<"2 --> Life Insurance"<<endl;
        cout<<"3 --> Home Insurance"<<endl;
        cout<<"Enter Choice : ";
        cin>>policy_choice;
        type = policy_choice;

        cout << "Enter Date Of Policy Creation [DD MM YYYY]: ";
        cin >> date[0];
        cin >> date[1];
        cin >> date[2];
        cout << "Date Noted : " << date[0] << "/" << date[1] << "/" << date[2] << "\n";

        cout << "Enter Age Of Applicant: ";
        cin>>age;
        if(age>=86 && policy_choice==1)
            {
                cout<<"You do not qualify for health insurance."<<endl; 
                return;
            }
        if(age>=51 && policy_choice==2)
            {
                cout<<"You do not qualify for life insurance."<<endl;   
                return;
            }
        if(age>=71 && policy_choice==3)
            {
                cout<<"You do not qualify for home insurance."<<endl;   
                return;
            }
        
            
        while(flag)
        {
            switch(policy_choice)
            {
                case 1:              
                    //cout<<"CRITICAL ILLNESS RIDER = 100!"<<endl; //meaning ?????????????????
                    total_premium=healthInsurance(age);
                    flag=false;
                    final_premium = total_premium;
                    break;
                    
                    
                case 2:  total_premium=lifeInsurance(age);
                    flag=false;
                    final_premium = total_premium;
                    break;
                    
                case 3:
                    cout<<"Enter Policy period in years or enter -9 for indefinite policy period "<<endl;
                    cin>>policy_period;
                    total_premium = homeInsurance(policy_period,age);
                    final_premium = total_premium;
                    flag=false;
                    break;
                    
                default:
                    cout<<"Does Not Exist.Try Again.";
            }
        }
    }
};