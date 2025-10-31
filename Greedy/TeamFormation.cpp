
1. Team must have all unique skills
2. Final max.possibile skills( skill "s" present then it must have "s-1" skill already present in team except for 0-index skill:: with min.size )
---------------------------------------------------
int TeamFormation(vector<int>& Skills)
{
    int n = Skill.size();
    sort(Skills.begin(),Skills.end());
    map<int,multiset<int>> team;
    for(int skill : Skills)
    {
        if(team[skill-1].empty())
        {
            team[skill].insert(1);
        }
        else
        {
            auto it = team[skill-1].begin();
            int small_size = *it;
            team[skill-1].erase(it);
            team[skill-1].insert(small_size+1);
        }
    }
    int ANS = INT_MAX;
    for(auto pair : team)
    {
        if( !pair.second.empty() )
        {
            int smallest = *(pair.second.begin());
            ANS = min(ANS,smallest);
        }
    }
    return ANS;
}