#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void nocycle(int iteration);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for(int i=0; i<candidate_count;i++)
    {
        if(strcasecmp(name,candidates[i]) == false)
        {
            ranks[rank]=i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for(int j = i+1; j < candidate_count; j++)
        {
             preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int i = 0;
    for (int high = 0; high < candidate_count; high++)
    {
        for(int low = 0; low < candidate_count; low++)
        {
            if(preferences[high][low]!=0 && (preferences[high][low] > preferences[low][high]))
            {
                pairs[i].winner = high;
                pairs[i].loser = low;
                i++;
                pair_count++;
            }
        }
    }
    //printf("%i\n", pair_count);
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    pair pairtemp;
    for(int i = 0; i < pair_count; i++)
    {
        for(int j = 0; j < pair_count; j++)
        {
            if(preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[i+1].winner][pairs[i+1].loser])
            {
                pairtemp=pairs[i];
                pairs[i]=pairs[i+1];
                pairs[i+1]=pairtemp;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
bool cycle=false;
void lock_pairs(void)
{
    // TODO
    for(int i = 0; i<candidate_count;i++)
    {
        cycle = false;
        nocycle(i);
        if(cycle == false)
        {
            locked[pairs[i].winner][pairs[i].loser]=true;
        }
    }
    return;
}
int current;
int visit[MAX];
//find a way to move accross the line
void nocycle(int iteration)
{
    current=pairs[iteration].loser;
    if(iteration < 0 || cycle == true)
    {
        return;
    }
    for(int i=iteration;i>-1;i--)
    {
        if(visit[i] >= 2)
        {
            cycle = true;
            return;
        }
        else if(current==pairs[i].winner)
        {
            current=pairs[i].loser;
            visit[i]++;
            cycle = false;
            nocycle(i);
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    bool notwinner[MAX] = {false};

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j =0; j< candidate_count; j++)
        {
            if(locked[i][j]==true)
            {
                notwinner[j]=true;
            }
        }
    }
    for (int i = 0; i < candidate_count;i++)
    {
        if(notwinner[i] != true )
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}