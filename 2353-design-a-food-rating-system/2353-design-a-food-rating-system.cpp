class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> cuisine_rat_food; // cuisine, rating-food
    unordered_map<string, string> food_cuisine;
    
    // this is the hidden technique -> by using this map we are saving reordering of set logic
    // using this map, we can directly get food rating
    unordered_map<string, int> food_rat;
    
    FoodRatings(vector<string>& foods, vector<string>& cui, vector<int>& rat) {
        int n = foods.size();
        for(int i = 0; i<n; i++) {
            cuisine_rat_food[cui[i]].insert({-rat[i], foods[i]});
            food_cuisine[foods[i]] = cui[i];
            food_rat[foods[i]] = rat[i];
        }
    }
    
    void changeRating(string food, int nr) {
        auto &cui = food_cuisine[food];
        cuisine_rat_food[cui].erase({-food_rat[food], food});
        cuisine_rat_food[cui].insert({-nr, food});
        food_rat[food] = nr;
    }
    
    string highestRated(string cui) {
        return cuisine_rat_food[cui].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */