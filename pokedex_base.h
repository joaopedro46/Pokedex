//Struct para armazenar dados dos pokemons
typedef struct
{
    int id;
    char nome[100];
    char tipo[100];
    float altura;
    float peso;
    int attack;
    int SP_attack;
    int defense;
    int SP_defense;
    int velocidade;
}pokemon;

void menu()
{
    printf("\t\t\tMENU\n");
    printf("\n\t1. Registrar Pokemon\n");
    printf("\t2. Listar Pokemons registrados\n");
    printf("\t3. Buscar e listar Pokemon\n");
    printf("\t4. Remover Pokemon do registro\n");
    printf("\t5. Fechar Pokedex\n");
    printf("\nDigite a opção desejada: ");
}

//Função que armazena os dados dos pokemons no arquivo
int registro()
{
    pokemon *new_pokemon = malloc(sizeof(pokemon));
    if(!new_pokemon)
    {
        printf("Falha ao alocar memória\n");
        exit(1);
    }
    printf("Alocação de memória bem sucedida\n");
    FILE *fp = fopen("Pokedex.dat", "r+");
    if(!fp)
    {
        printf("Falha ao abrir o arquivo\n");
    }
    printf("File opened successfully\n");
    
    char confirmation = 'n';
    while(confirmation == 'n' || confirmation == 'N')
    {
        system("cls");
        new_pokemon->id = rand() % 1000;
        fflush(stdin);
        printf("Nome do Pokemon: ");
        fgets(new_pokemon->nome, sizeof(new_pokemon->nome),stdin);
        printf("Tipo do Pokemon: ");
        fgets(new_pokemon->tipo, sizeof(new_pokemon->tipo),stdin);
        printf("Altura do Pokemon: ");
        scanf("%f", &new_pokemon->altura);
        printf("Peso do Pokemon: ");
        scanf("%f", &new_pokemon->peso);
        printf("Valor do atributo de Ataque: ");
        scanf("%d", &new_pokemon->attack);
        printf("Valor do atributo de SP Ataque: ");
        scanf("%d", &new_pokemon->SP_attack);
        printf("Valor do atributo de Defesa: ");
        scanf("%d", &new_pokemon->defense);
        printf("Valor do atributo de SP Defesa: ");
        scanf("%d", &new_pokemon->SP_defense);
        printf("Valor do atributo de Velocidade: ");
        scanf("%d", &new_pokemon->velocidade);

        printf("\nNome: %s",new_pokemon->nome);
        printf("Tipo: %s",new_pokemon->tipo);
        printf("Altura: %.2f\n",new_pokemon->altura);
        printf("Peso: %.2f\n",new_pokemon->peso);
        printf("Attack: %d\n",new_pokemon->attack);
        printf("SP Ataque: %d\n",new_pokemon->SP_attack);
        printf("Defense: %d\n",new_pokemon->defense);
        printf("SP Defesa: %d\n",new_pokemon->SP_defense);
        printf("Velocidade: %d\n",new_pokemon->velocidade);
        fflush(stdin);
        printf("Os dados digitados estão corretos? ");
        scanf("%c",&confirmation);
    }
    

    int test = fwrite(new_pokemon, 1, sizeof(pokemon), fp);
    if(!test)
    printf("Erro ao escrever no arquivo");
    fclose(fp);
    free(new_pokemon);
    return 0;
}

int lista()
{

}