package by.hiber.db.javac.dao;

import by.hiber.db.javac.interfaces.Identifiable;
import by.hiber.db.javac.interfaces.Loggable;
import by.hiber.db.javac.interfaces.Reflective;
import org.hibernate.query.Query;

import java.io.Serializable;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import static by.hiber.db.javac.util.HibernateUtil.getCurrentSession;

public abstract class AbstractHibernateDao
                     <T extends Identifiable,
                     PK extends Serializable>
                     implements GenericDao<T, PK>, Loggable, Reflective {

    private final T entityObj;

    { entityObj = (T) getGenericObject(0); }

    public PK save(T obj) { // сохраняем
        getCurrentSession().save(obj);
        return (PK) obj.getId();
    }

    @Override
    public void update(T obj) {
        getCurrentSession().update(obj);
    } // обновляем

    @Override
    public List<T> getAll() { // берем все записи
        String hql = String.format("select target from %s target", entityObj.getClass().getName());
        Query query = getCurrentSession().createQuery(hql);
        return query.list();
    }

    @Override
    public List<T> getListByQuery(String hql) {
        return (List<T>) getCurrentSession().createQuery(hql).list();
    }

    @Override
    public Set<PK> getPkSetByQuery(String hql) {
        return new HashSet<>(getCurrentSession().createQuery(hql).list());
    }

    @Override
    public int executeQuery(String hql, Map<String, Object> parameters) { // квери запрос
        Query query = getCurrentSession().createQuery(hql);
        query.setProperties(parameters);
        return query.executeUpdate();
    }

    @Override
    public T getById(PK id) { // берем по айдишнику
        String hql = String.format("select target from %s target where id = :targetId", entityObj.getClass().getName());
        Query query = getCurrentSession().createQuery(hql);
        query.setParameter("targetId", id);
        return (T) query.uniqueResult();
    }

    @Override
    public void delete(PK id) { // чистим по айдишнику
        T obj = (T) getCurrentSession().load(entityObj.getClass(), id);
        getCurrentSession().delete(obj);
    }

    @Override
    public void delete(T obj) {
        getCurrentSession().delete(obj);
    } // чистим

}
