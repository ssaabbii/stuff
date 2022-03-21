#pragma once
#include "Player.h"
#include "Model.h"


class Bot : public Player {
public:
    bool InputNumber(Model* model) override
    {
        std::vector<char> number;
        number.resize(4);
    tryAgain:
        bool is_used[10] = { false }; 
        srand(time(NULL));   
        for (int i = 0; i < 4; ++i) {  
            int idx = rand() % 10;
            if (!is_used[idx]) {
                number[i] = idx + 48;
                is_used[idx] = true;
            }
            else {
                --i;
            }
        }
        std::vector<info> history = model->GetHistory();
        for (auto& i : history) {  
            if ((model->GetBulls(number, i.number) != i.bulls) || (model->GetCows(number, i.number) != i.cows))
                goto tryAgain; 
        }
        model->SetNumber(number);
        return true;
    }

    ~Bot() override = default;

};
