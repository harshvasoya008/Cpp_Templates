struct pair_hash {
    std::size_t operator () (const std::pair<lli,lli> &p) const {
        auto h1 = std::hash<lli>{}(p.first);
        auto h2 = std::hash<lli>{}(p.second);
        return h1 ^ h2;
    }
};
