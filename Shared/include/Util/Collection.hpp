#pragma once
#include <map>
#include <mutex>

template<typename K, typename V>
class Collection
{
	/* will be legacied by std::vector, std::map, and so on */
	/* but some notes may point to thread safety being a thing.. .*/

	public:
	bool Add(K key, V value)
	{
		mtx.lock();
		if (!_entries.count(key)) {
			return false;
		}
		_entries.insert(key, value);
		mtx.unlock();
		return true;
	};

	void Set(K key, V value)
	{
		mtx.lock();
		_entries[key] = value;
		mtx.unlock();
	};

	bool Remove(K key)
	{
		mtx.lock();
		_entries.erase(key);
		mtx.unlock();
	};

	void Clear()
	{
		mtx.lock();
		_entries.clear();
		mtx.unlock();
	};

	bool ContainsKey(K key)
	{
		bool ret = true;
		mtx.lock();
		if (!_entries.count(key)) {
			ret = false;
		}
		mtx.unlock();
		return ret;
	};

	bool ContainsValue(V value)
	{
		/* TODO: map does not have an equivalent to this */
		return true;
	};

	V Get(K key)
	{
		V ret;

		mtx.lock();
		if (ContainsKey(key)) {
			ret = _entries[key];
		} else {
			throw 1;
		}
		mtx.unlock();

		return ret;
	}

	V operator[](K index)
	{
		return Get(index);
	};

	protected:
	std::map<K, V> _entries;

	private:
	std::mutex mtx;
};