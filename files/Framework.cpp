#include "Framework.h"


std::array<std::vector<Framework*>, LAYER> framework;

clock_t start_time, end_time; 
double ft;


void fw_routine() {
	start_time = clock();  	

	for(int i = 0; i < framework.size(); i ++) {
		if(framework[i].size() < framework[i].capacity())
			framework[i].shrink_to_fit();
		
		for (auto it = framework[i].begin(); it != framework[i].end();) {
			auto& ptr = *it;

			if (ptr != nullptr) {
				ptr->render();
				ptr->check_collision();
				ptr->update();	

				++it; 
			}

			else
				it = framework[i].erase(it);
		}
	}

	end_time = clock();  

	ft = (double)(end_time - start_time) / 1000;
}


void fw_add(Framework*&& object, int layer) {
	framework[layer].push_back(object);
}


void fw_delete(Framework* object, int layer) {
	auto target = std::find(framework[layer].begin(), framework[layer].end(), object);

	if (target != framework[layer].end()) {
		delete* target; 
		*target = nullptr;
	}
}


void fw_sweep_layer(int layer) {
	for (auto it = framework[layer].begin(); it != framework[layer].end();) {
		auto& ptr = *it;
		auto target = std::find(framework[layer].begin(), framework[layer].end(), ptr);

		delete* target;
		*target = nullptr;

		it++;
	}
}


void fw_sweep() {
	for (int i = 0; i < framework.size(); i++) {
		for (auto it = framework[i].begin(); it != framework[i].end();) {
			auto& ptr = *it;
			auto target = std::find(framework[i].begin(), framework[i].end(), ptr);

			delete* target;
			*target = nullptr;

			it++;
		}
	}
}
