/*
 *                         Vortex Lite
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $LITE_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
#ifndef CPP_DDS_OPENSPLICE_ENTITYCONTAINER_H
#define CPP_DDS_OPENSPLICE_ENTITYCONTAINER_H


namespace DDS
{
  namespace OpenSplice
  {
    class EntityContainer
    {
    protected:
        /*
         * Cleanup
         */
        template <class TFactory> DDS::ReturnCode_t wlReq_deleteFactoryList (DDS::OpenSplice::ObjSet *entityList)
        {
          DDS::ReturnCode_t result = DDS::RETCODE_OK;
          DDS::ObjSeq_var objSeq = entityList->getObjSeq();
          DDS::ULong i, nrEntities = objSeq->length();
          for (i = 0; i < nrEntities && result == DDS::RETCODE_OK; i++) {
            TFactory entity = dynamic_cast<TFactory>(objSeq[i].in());
            result = entity->delete_contained_entities();
            if (result == DDS::RETCODE_OK) {
              result = entity->deinit();
              if (result == DDS::RETCODE_OK) {
                entityList->removeElement(entity) ? result = DDS::RETCODE_OK : result = DDS::RETCODE_ERROR;
              }
            }
          }
          return result;
        }

        template <class TEntity> DDS::ReturnCode_t wlReq_deleteEntityList (DDS::OpenSplice::ObjSet *entityList)
        {
          DDS::ReturnCode_t result = DDS::RETCODE_OK;
          DDS::ObjSeq_var objSeq = entityList->getObjSeq();
          DDS::ULong i, nrEntities = objSeq->length();
          for (i = 0; i < nrEntities && result == DDS::RETCODE_OK; i++) {
            TEntity entity = dynamic_cast<TEntity>(objSeq[i].in());
            result = entity->deinit();
            if (result == DDS::RETCODE_OK) {
              entityList->removeElement(entity) ? result = DDS::RETCODE_OK : result = DDS::RETCODE_ERROR;
            }
          }
          return result;
        }
    };
  }
}

#endif /* CPP_DDS_OPENSPLICE_ENTITYCONTAINER_H */
