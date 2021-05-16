/**************************

Empresa: Capgemini 
Desenvolvedor: Henrique Freitas Novais
Data: 16/05/2021
Programa: Cadastro de anúncios

Descrição: Sistema de gestão de anúncios e rastreios 
           dos resultados da campanha.

***************************/

#include <stdio.h>

typedef struct {
	int dia;
	int mes;
	int ano;
} Data;

int bissexto (int ano);

int dias_mes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main()
{
    // Declarações   
    float v_investido;  // Valor investido por dia
    float ref_visu;     // Referencia de visualizações
    int num_compart;  // Número de compartilhamentos diários
    int num_cliq;     // Número de cliques diários
    int tot_visu = 0;       // Total de visualizações diárias
    int num_visu;       // Número de visualizações baseado no investido dia                 
    int ref_comp;       // Referencia de compartilhamentos
    int max_comp;       // Máximo de compartilhamentos por dia
    int dd_ini,mm_ini,aa_ini; // Dia de início, mês de início, ano de início
    int dd_fim,mm_fim,aa_fim; // Dia final, mês final, ano final
    int ctrl_data = 0; // variável que irá validar ou não as condições de data
    char data_ini; // Data inicial
    char data_fim; // Data final
    Data dia_ini, dia_fim; // 
    long idias, fdias; // Para calcular distância entre os dias
    long def_anos = 0; // Diferença entre os anos
    register int i; // Validação para ano bissexto
	int dbissexto; // Ano bissexto
	int vtotal_investido; // 
	char cliente  [30]; // Nome do cliente
	char anuncio  [30]; // Nome do anúncio
	int tot_visu2; // Total de visualizações finais
	int num_comparttotal; // Total de compartilhamentos finais
	int num_cliqtot; // Total de cliques finais
	
	//Informações do anúncio e do cliente
	printf("Digite o nome do anuncio: \n");
	scanf("%s", &anuncio); 
	printf("Digite o nome do cliente: \n");
	scanf("%s", &cliente);
	
	//Data de início
	do
	{  
	    
	    
	ctrl_data = 0;
    printf("Digite a data de inicio (DD/MM/AAAA formato): ");
    scanf("%d/%d/%d",&dd_ini,&mm_ini,&aa_ini);
    //Validando Ano
    if(aa_ini>=1900 && aa_ini<=9999)
    {
        //Validando mês
        if(mm_ini>=1 && mm_ini<=12)
        {
            //Validando dia
                        		    
            if((dd_ini>=1 && dd_ini<=31) && (mm_ini==1 || mm_ini==3 || mm_ini==5 || mm_ini==7 || mm_ini==8 || mm_ini==10 || mm_ini==12))
                    	
				ctrl_data = 0;
											    
            else if((dd_ini>=1 && dd_ini<=30) && (mm_ini==4 || mm_ini==6 || mm_ini==9 || mm_ini==11))
                      
				ctrl_data = 0;
							    
            else if((dd_ini>=01 && dd_ini<=28) && (mm_ini==02))
                       
				ctrl_data = 0;
							
            else if(dd_ini==29 && mm_ini==2 && (aa_ini%400==0 ||(aa_ini%4==0 && aa_ini%100!=0)))
                    
				ctrl_data = 0;
				
			if(dd_ini>31){		
                ctrl_data ++; 
			    printf("Dia não é válido.\n") ;
			    	}
             
        }
        else
        {
        	ctrl_data ++;
            printf("Mês não é válido, por favor digite a data novamente.\n");          
        }
    }
    else
    {
    	ctrl_data++;
        printf("Ano não é válido, por favor digite a data novamente.\n");
    }      
    }while (ctrl_data>0);
    data_ini = (dd_ini, mm_ini, aa_ini);
    dia_ini.dia = dd_ini;
    dia_ini.mes = mm_ini;
    dia_ini.ano = aa_ini;
    
    //Data de término   
    do
	{
    ctrl_data = 0;
    printf("Digite a data de termino (DD/MM/AAAA formato): ");
    scanf("%d/%d/%d",&dd_fim,&mm_fim,&aa_fim);
    //Validando Ano
   
    if(aa_fim>=1900 && aa_fim<=9999)
    {
        //Validando mês
        if(mm_fim>=1 && mm_fim<=12)
        {
            //Validando dia
            
            if((dd_fim>=1 && dd_fim<=31) && (mm_fim==1 || mm_fim==3 || mm_fim==5 || mm_fim==7 || mm_fim==8 || mm_fim==10 || mm_fim==12))
                                
				ctrl_data = 0;
			    
            else if((dd_fim>=1 && dd_fim<=30) && (mm_fim==4 || mm_fim==6 || mm_fim==9 || mm_fim==11))
                                
				ctrl_data = 0;
			    
            else if((dd_fim>=1 && dd_fim<=28) && (mm_fim==2))
                                 
				ctrl_data = 0;
			
            else if(dd_fim==29 && mm_fim==2 && (aa_fim%400==0 ||(aa_fim%4==0 && aa_fim%100!=0)))
                                 
				ctrl_data = 0;
			    
            if(dd_fim>31){
			            
               ctrl_data++;
			    printf("Dia nao e valido.\n");
            }                   
        }
        else
        {
        	ctrl_data++;
            printf("Mes nao e valido, por favor digite a data novamente.\n");
        }
    }
    else
    {
    	ctrl_data++;
        printf("Ano nao e valido, por favor digite a data novamente.\n");
        
    }
        
        //
        
        if(aa_ini <= aa_fim)  
		{	
		if(mm_ini <= mm_fim)
		{
		if(dd_ini <= dd_fim)
		{
		}
		else
		{
			if (dd_ini > dd_fim && aa_ini >= aa_fim)
			{
			ctrl_data++;
	    	printf("Data de inicio nao pode ser maior que a data de termino");	
			}
			if (dd_ini > dd_fim && mm_ini > mm_fim && aa_ini > aa_fim)
			{
			ctrl_data++;
	    	printf("Data de inicio nao pode ser maior que a data de termino");	
			}
			if (mm_ini > mm_fim)
			{
			ctrl_data++;
	    	printf("Data de inicio nao pode ser maior que a data de termino");
	    	}else{
	    		if (aa_ini > aa_fim)
				{
				ctrl_data++;
	    		printf("Data de inicio nao pode ser maior que a data de termino");	    			
				}
			}
		}	
		}
		else
		{
		ctrl_data++;
		printf("Data de inicio nao pode ser maior que a data de termino");
		}
	 	}
	 	else
	 	{
	 	ctrl_data++;
		printf("Data de inicio nao pode ser maior que a data de termino");	
		}  
    
    }while (ctrl_data>0);
    dia_fim.dia = dd_fim;
    dia_fim.mes = mm_fim;
    dia_fim.ano = aa_fim;
    
	data_fim = (dd_fim, mm_fim, aa_fim);      	
	
	// Obter intervalo de datas em dias 	
	
	
	idias = dia_ini.dia;
	dbissexto = bissexto (dia_ini.ano);
	for (i = dia_ini.mes - 1; i > 0; --i)
		idias += dias_mes[dbissexto][i];

	fdias = dia_fim.dia;
	dbissexto = bissexto (dia_fim.ano);
	for (i = dia_fim.mes - 1; i > 0; --i)
		fdias += dias_mes[dbissexto][i];

	while (dia_ini.ano < dia_fim.ano)
		def_anos += 365 + bissexto(dia_ini.ano++);

	def_anos - idias + fdias;
	
    // Obter valor a ser investido		
    printf("Digite o valor a ser investido diariamente: R$: "); 
    scanf ("%f", &v_investido);
    
    // Atribuindo valores para as variáveis
    ref_visu = 30;
    max_comp = 4;
    vtotal_investido = v_investido * (def_anos - idias + fdias);
    num_visu = (vtotal_investido * ref_visu);
    num_compart = (v_investido * ref_visu) * 0.12 * 0.15;
    num_cliq = (v_investido * ref_visu) * 0.12;
    num_comparttotal = num_compart * (def_anos - idias + fdias);      
    num_cliqtot = num_cliq * (def_anos - idias + fdias);
    
    if (num_compart >= max_comp)
        {
        num_compart = 4;    
        tot_visu = num_visu + max_comp * 40;
        }
    else
        {
        tot_visu = num_visu + (num_compart * 40);
        }
        
        tot_visu2 = tot_visu + num_comparttotal;
        
    printf("Valor total investido: R$: %d\n ", vtotal_investido );
    printf("Quantidade maxima de visualizacoes: %d\n", tot_visu2);
    printf("Quantidade maxima de cliques: %d\n", num_cliqtot);
    printf("Quantidade maxima de compartilhamentos: %d\n", num_comparttotal);
    return 0;
}
int bissexto (int ano) {
	return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}