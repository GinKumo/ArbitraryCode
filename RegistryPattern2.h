// -----------------
// RegistryPattern.h
// -----------------

// http://martinfowler.com/eaaCatalog/registry.html

#ifndef RegistryPattern_h
#define RegistryPattern_h

#include <map>     // map
#include <utility> // make_pair, pair

template <typename K, typename V>
class Registry {
    public:
        using key_type       = K;
        using value_type     = V;

        using container_type = std::map<key_type, value_type>;

        using iterator       = typename container_type::iterator;
        using const_iterator = typename container_type::const_iterator;

    private:
        static container_type& only () {
            static container_type c;
            return c;}

    public:
        static void add (const key_type& k, const value_type& v) {
            std::pair<iterator, bool> p = only().insert(std::make_pair(k, v));
            assert(p.second);}
        Registry (const key_type& k, const value_type& v) {
            add(k, v);}

                  Registry   (const Registry&) = default;
                  ~Registry  ()                = default;
        Registry& operator = (const Registry&) = default;
        static value_type get (const key_type& k) {
            const_iterator p = only().find(k);
            if (p == only().end())
                return value_type();
            return p->second;}};

#endif // Registry_h
