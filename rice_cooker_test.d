import rice_cooker;


unittest
{

    {
        Content c;
        setName(c, "Vegetables");
        assert(getName(c) == "Vegetables");
    }

    {
        Content c;
        setQuantity(c, 3.14);
        assert(getQuantity(c) == 3.14);
    }

    {
        RiceCooker rc;
        setCapacity(rc, 5.0);
        assert(getCapacity(rc) == 5.0);
    }

}
