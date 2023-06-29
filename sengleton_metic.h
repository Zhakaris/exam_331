#include <QCoreApplication>
#include <QVariant>
#include <QDebug>

class MetricRegist;

class MetricRegist_Destroyer
{
    private:
        MetricRegist * p_instance;
    public:
        ~MetricRegist_Destroyer() { delete p_instance;}
        void initialize(MetricRegist * p){p_instance = p;}
};

class MetricRegist
{
    private:
        static MetricRegist * p_instance; // Статик - память не выделяется классом, единственный экземлпяр
        static MetricRegist_Destroyer destroyer;
    protected:
        MetricRegist();
        MetricRegist(const MetricRegist& );
        MetricRegist& operator = (MetricRegist &);
        ~MetricRegist();
        friend class MetricRegist_Destroyer;
    public:
        bool add_metr(int resp_t, int wait_t);
        bool show_mert();
        int coutn_cometr(int key);
        void init(QString filename);

        static MetricRegist *getInstance(){
            if (!p_instance)
            {
                p_instance = new MetricRegist();
                destroyer.initialize(p_instance); // Присваивание ссылки на синглтн в Destroyer
            }
            return p_instance;
        }
};
