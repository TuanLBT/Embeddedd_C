//#line 2 "/home/pi/do_an_ws/src/dynamic_reconfigure/templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the costmap_2d package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __costmap_2d__COSTMAP2DCONFIG_H__
#define __costmap_2d__COSTMAP2DCONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace costmap_2d
{
  class Costmap2DConfigStatics;

  class Costmap2DConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      virtual ~AbstractParamDescription() = default;

      virtual void clamp(Costmap2DConfig &config, const Costmap2DConfig &max, const Costmap2DConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const Costmap2DConfig &config1, const Costmap2DConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, Costmap2DConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const Costmap2DConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, Costmap2DConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const Costmap2DConfig &config) const = 0;
      virtual void getValue(const Costmap2DConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T Costmap2DConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T Costmap2DConfig::* field;

      virtual void clamp(Costmap2DConfig &config, const Costmap2DConfig &max, const Costmap2DConfig &min) const override
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const Costmap2DConfig &config1, const Costmap2DConfig &config2) const override
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, Costmap2DConfig &config) const override
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const Costmap2DConfig &config) const override
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, Costmap2DConfig &config) const override
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const Costmap2DConfig &config) const override
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const Costmap2DConfig &config, boost::any &val) const override
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      virtual ~AbstractGroupDescription() = default;

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, Costmap2DConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, Costmap2DConfig &top) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const override
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T PT::* field;
      std::vector<Costmap2DConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(Costmap2DConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("transform_tolerance"==(*_i)->name){transform_tolerance = boost::any_cast<double>(val);}
        if("update_frequency"==(*_i)->name){update_frequency = boost::any_cast<double>(val);}
        if("publish_frequency"==(*_i)->name){publish_frequency = boost::any_cast<double>(val);}
        if("width"==(*_i)->name){width = boost::any_cast<int>(val);}
        if("height"==(*_i)->name){height = boost::any_cast<int>(val);}
        if("resolution"==(*_i)->name){resolution = boost::any_cast<double>(val);}
        if("origin_x"==(*_i)->name){origin_x = boost::any_cast<double>(val);}
        if("origin_y"==(*_i)->name){origin_y = boost::any_cast<double>(val);}
        if("footprint"==(*_i)->name){footprint = boost::any_cast<std::string>(val);}
        if("robot_radius"==(*_i)->name){robot_radius = boost::any_cast<double>(val);}
        if("footprint_padding"==(*_i)->name){footprint_padding = boost::any_cast<double>(val);}
      }
    }

    double transform_tolerance;
double update_frequency;
double publish_frequency;
int width;
int height;
double resolution;
double origin_x;
double origin_y;
std::string footprint;
double robot_radius;
double footprint_padding;

    bool state;
    std::string name;

    
}groups;



//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double transform_tolerance;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double update_frequency;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double publish_frequency;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      int width;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      int height;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double resolution;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double origin_x;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double origin_y;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      std::string footprint;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double robot_radius;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double footprint_padding;
//#line 231 "/home/pi/do_an_ws/src/dynamic_reconfigure/templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("Costmap2DConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const Costmap2DConfig &__max__ = __getMax__();
      const Costmap2DConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const Costmap2DConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const Costmap2DConfig &__getDefault__();
    static const Costmap2DConfig &__getMax__();
    static const Costmap2DConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const Costmap2DConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void Costmap2DConfig::ParamDescription<std::string>::clamp(Costmap2DConfig &config, const Costmap2DConfig &max, const Costmap2DConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class Costmap2DConfigStatics
  {
    friend class Costmap2DConfig;

    Costmap2DConfigStatics()
    {
Costmap2DConfig::GroupDescription<Costmap2DConfig::DEFAULT, Costmap2DConfig> Default("Default", "", 0, 0, true, &Costmap2DConfig::groups);
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.transform_tolerance = 0.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.transform_tolerance = 10.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.transform_tolerance = 0.3;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("transform_tolerance", "double", 0, "Specifies the delay in transform (tf) data that is tolerable in seconds.", "", &Costmap2DConfig::transform_tolerance)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("transform_tolerance", "double", 0, "Specifies the delay in transform (tf) data that is tolerable in seconds.", "", &Costmap2DConfig::transform_tolerance)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.update_frequency = 0.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.update_frequency = 100.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.update_frequency = 5.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("update_frequency", "double", 0, "The frequency in Hz for the map to be updated.", "", &Costmap2DConfig::update_frequency)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("update_frequency", "double", 0, "The frequency in Hz for the map to be updated.", "", &Costmap2DConfig::update_frequency)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.publish_frequency = 0.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.publish_frequency = 100.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.publish_frequency = 0.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("publish_frequency", "double", 0, "The frequency in Hz for the map to publish display information.", "", &Costmap2DConfig::publish_frequency)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("publish_frequency", "double", 0, "The frequency in Hz for the map to publish display information.", "", &Costmap2DConfig::publish_frequency)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.width = 0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.width = 2147483647;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.width = 10;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<int>("width", "int", 0, "The width of the map in meters.", "", &Costmap2DConfig::width)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<int>("width", "int", 0, "The width of the map in meters.", "", &Costmap2DConfig::width)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.height = 0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.height = 2147483647;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.height = 10;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<int>("height", "int", 0, "The height of the map in meters.", "", &Costmap2DConfig::height)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<int>("height", "int", 0, "The height of the map in meters.", "", &Costmap2DConfig::height)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.resolution = 0.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.resolution = 50.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.resolution = 0.05;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("resolution", "double", 0, "The resolution of the map in meters/cell.", "", &Costmap2DConfig::resolution)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("resolution", "double", 0, "The resolution of the map in meters/cell.", "", &Costmap2DConfig::resolution)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.origin_x = -std::numeric_limits<double>::infinity();
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.origin_x = std::numeric_limits<double>::infinity();
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.origin_x = 0.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("origin_x", "double", 0, "The x origin of the map in the global frame in meters.", "", &Costmap2DConfig::origin_x)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("origin_x", "double", 0, "The x origin of the map in the global frame in meters.", "", &Costmap2DConfig::origin_x)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.origin_y = -std::numeric_limits<double>::infinity();
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.origin_y = std::numeric_limits<double>::infinity();
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.origin_y = 0.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("origin_y", "double", 0, "The y origin of the map in the global frame in meters.", "", &Costmap2DConfig::origin_y)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("origin_y", "double", 0, "The y origin of the map in the global frame in meters.", "", &Costmap2DConfig::origin_y)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.footprint = "";
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.footprint = "";
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.footprint = "[]";
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<std::string>("footprint", "str", 0, "The footprint of the robot specified in the robot_base_frame coordinate frame as a list in the format: [ [x1, y1], [x2, y2], ...., [xn, yn] ].", "", &Costmap2DConfig::footprint)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<std::string>("footprint", "str", 0, "The footprint of the robot specified in the robot_base_frame coordinate frame as a list in the format: [ [x1, y1], [x2, y2], ...., [xn, yn] ].", "", &Costmap2DConfig::footprint)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.robot_radius = 0.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.robot_radius = 10.0;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.robot_radius = 0.46;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("robot_radius", "double", 0, "The radius of the robot in meters, this parameter should only be set for circular robots, all others should use the footprint parameter described above.", "", &Costmap2DConfig::robot_radius)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("robot_radius", "double", 0, "The radius of the robot in meters, this parameter should only be set for circular robots, all others should use the footprint parameter described above.", "", &Costmap2DConfig::robot_radius)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.footprint_padding = -std::numeric_limits<double>::infinity();
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.footprint_padding = std::numeric_limits<double>::infinity();
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.footprint_padding = 0.01;
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("footprint_padding", "double", 0, "How much to pad (increase the size of) the footprint, in meters.", "", &Costmap2DConfig::footprint_padding)));
//#line 291 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(Costmap2DConfig::AbstractParamDescriptionConstPtr(new Costmap2DConfig::ParamDescription<double>("footprint_padding", "double", 0, "How much to pad (increase the size of) the footprint, in meters.", "", &Costmap2DConfig::footprint_padding)));
//#line 246 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(Costmap2DConfig::AbstractGroupDescriptionConstPtr(new Costmap2DConfig::GroupDescription<Costmap2DConfig::DEFAULT, Costmap2DConfig>(Default)));
//#line 369 "/home/pi/do_an_ws/src/dynamic_reconfigure/templates/ConfigType.h.template"

      for (std::vector<Costmap2DConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<Costmap2DConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<Costmap2DConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    Costmap2DConfig __max__;
    Costmap2DConfig __min__;
    Costmap2DConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const Costmap2DConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static Costmap2DConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &Costmap2DConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const Costmap2DConfig &Costmap2DConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const Costmap2DConfig &Costmap2DConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const Costmap2DConfig &Costmap2DConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<Costmap2DConfig::AbstractParamDescriptionConstPtr> &Costmap2DConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<Costmap2DConfig::AbstractGroupDescriptionConstPtr> &Costmap2DConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const Costmap2DConfigStatics *Costmap2DConfig::__get_statics__()
  {
    const static Costmap2DConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = Costmap2DConfigStatics::get_instance();

    return statics;
  }


}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __COSTMAP2DRECONFIGURATOR_H__
