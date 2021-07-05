#include<bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get array_size */
	int32_t array_size;
	std::cin >> array_size;

	/* get number_of_queries */
	int32_t number_of_queries;
	std::cin >> number_of_queries;

	/* get array_elements */
	std::vector<int32_t> array(array_size);
	for(int32_t i{0}; i < array_size; i++) {
	    std::cin >> array.at(i);
	}

	/* evaluate minimum_number_of_sets */
	std::set<int32_t> s;
	for(int32_t i{0}; i < array_size; i++) {
	    int32_t start_position_of_set{i + 1};
	    s.insert(start_position_of_set);

	    /* elements which is satisfying given
	     * constraints will be in set {i+1}*/
	    while((i+1) < array_size && array[i+1] % array[i] == 0){
            i++;
	    }
	}

    int32_t operation_type;
	for(int32_t i{0};i < number_of_queries;i++)	{
	    /* get operation_type */
	    std::cin >> operation_type;

	    if(operation_type == 1) {
	        /* get position */
	        int32_t position;
	        std::cin >> position;

	        /* get value */
	        int32_t value;
	        std::cin >> value;

	        int32_t index{position - 1};
	        /* update index with corresponding value */
            array[index] = value;

            /* insert start position of elements
             * which are probable for change */
	        s.insert(position);s.insert(position + 1);

	        if(position > 1 && array[index] % array[index - 1] == 0) {
                /* if array[index] element has same set as array[index-1]
                 * then remove corresponding set inserted for array[index]*/
	            auto iterator {s.find(position)};s.erase(iterator);
	        }

	        if(position < array_size && array[index+1] % array[index] == 0) {
                /* if array[index+1] element  has same set as array[index]
                 * then remove corresponding set inserted for array[index+1] */
	            auto iterator {s.find(position + 1)};s.erase(iterator);
	        }
	    } else {
	        /* get index_value */
	        int32_t index;
	        std::cin >> index;

            /* evaluate left-most element of the
             * set in which i-th element lies */
	        auto initial_index{s.upper_bound(index)};
	        initial_index--;

	        /* print appropriate message */
	        std::cout << *initial_index << std::endl;
	    }
	}
	return 0;
}