

class Solution {
public:
       void mapping(unordered_map<int, int>& id_to_idx, vector<Employee*>& employees) const {
              for(int i {}; i < (int) employees.size(); ++i) 
                    id_to_idx[employees[i]->id] = i;
        }

        int getImportanceHelper(unordered_map<int, int>& id_to_idx, vector<Employee*>& employees, int cur_id) const {
            int cur_idx {id_to_idx[cur_id]};

            int importance {employees[cur_idx]->importance};
            for(int child_id: employees[cur_idx]->subordinates)
                importance += getImportanceHelper(id_to_idx, employees, child_id);
            
            return importance;
        }

       int getImportance(vector<Employee*>& employees, int id) {
            unordered_map<int, int> id_to_idx;
            mapping(id_to_idx, employees);

            return getImportanceHelper(id_to_idx, employees, id);
       }
};     