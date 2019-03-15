/* 
 * File:   lrucache.hpp
 * Author: Alexander Ponomarev
 *
 * Created on June 20, 2013, 5:09 PM
 */

#ifndef _LRUCACHE_HPP_INCLUDED_
#define	_LRUCACHE_HPP_INCLUDED_

namespace cache {

template<typename key_t, typename value_t>
class lru_cache_q {
public:
	lru_cache_q(size_t max_size) :
		_max_size(max_size) {
	}
	
	void put(const key_t& key, const value_t& value) {
        if (_cathe_data.contains(key))
        {
            _cache_items_list.move(_cache_items_list.indexOf(key),0);
        }
        else
        {
            _cache_items_list.push_front(key);
        }

        _cathe_data.insert(key,value);
		
		if (_cathe_data.size() > _max_size) {
			auto last = _cache_items_list.last();
            _cathe_data.remove(last);
			_cache_items_list.pop_back();
		}
	}
	
	const value_t& get(const key_t& key) {
		auto it = _cathe_data.find(key);
		if (it == _cathe_data.end()) {
			throw std::range_error("There is no such key in cache");
		} else {
            _cache_items_list.move(_cache_items_list.indexOf(key),0);
            return _cathe_data[key];
		}
	}
	
	bool exists(const key_t& key) const {
		return _cathe_data.contains(key);
	}
	
	size_t size() const {
		return _cathe_data.size();
	}
	
private:
	QList<key_t> _cache_items_list;
    QHash<key_t,value_t> _cathe_data;
	size_t _max_size;
};

} // namespace lru

#endif	/* _LRUCACHE_HPP_INCLUDED_ */